{-# LANGUAGE DeriveFunctor, DeriveFoldable, DeriveTraversable #-}
import Control.Arrow
import Control.Monad
import Control.Monad.IO.Class
import Control.Monad.Trans.Class
import Control.Monad.Trans.RWS.Strict hiding (local)
import Control.Monad.Trans.State.Strict (StateT)
import qualified Control.Monad.Trans.State.Strict as State
import Data.Char
import Data.Functor.Identity
import Data.List (intersperse)
import Data.Map (Map)
import qualified Data.Map as Map
import Data.Monoid
import Text.ParserCombinators.ReadP hiding (get)

andM :: Monad m => [m Bool] -> m Bool
andM = foldM (\i j -> if not i then return False else j) True

data SimpleTerm a
  = Variable a
  | Relational String [SimpleTerm a]
  deriving (Eq, Ord, Functor, Foldable, Traversable)

instance Show a => Show (SimpleTerm a) where
  showsPrec _ term = case term of
    Variable a -> showChar '#' . shows a
    Relational name [] -> showString name
    Relational name ts -> showChar '[' . showString name . showString ": " .
      (foldr1 (.) $ intersperse (showString ", ") $ map shows ts) . showChar ']'

data ComplexTerm a
  = SimpleTerm (SimpleTerm a)
  | EqualityAssertion (SimpleTerm a) (SimpleTerm a)
  | NonEqualityAssertion (SimpleTerm a) (SimpleTerm a)
  deriving (Show, Functor, Foldable, Traversable)

data Rule a = Rule [ComplexTerm a] (SimpleTerm a)
  deriving (Show, Functor, Foldable, Traversable)

data Query a = Query [ComplexTerm a]
  deriving (Show, Functor, Foldable, Traversable)

data Op
  = RuleOp (Rule String)
  | QueryOp (Query String)
  | QuitOp
  | NoOp
  deriving (Show)

instance Read Op where
  readsPrec _ = readP_to_S op
    where
    name :: ReadP String
    name = (:) <$> satisfy isAlpha <*> munch (\c -> isAlphaNum c || c == '-')

    simpleTerm :: ReadP (SimpleTerm String)
    simpleTerm = choice
      [ Relational <$> name <*> pure []
      , Variable <$ char '#' <*> name
      , Relational <$ char '[' <*> name <* string ": "
          <*> sepBy1 simpleTerm (string ", ") <* char ']'
      ]

    complexTerm :: ReadP (ComplexTerm String)
    complexTerm = choice
      [ SimpleTerm <$> simpleTerm
      , EqualityAssertion <$ char '<' <*> simpleTerm
          <* string " = " <*> simpleTerm <* char '>'
      , NonEqualityAssertion <$ char '<' <*> simpleTerm
          <* string " /= " <*> simpleTerm <* char '>'
      ]

    op :: ReadP Op
    op = choice
      [ RuleOp . Rule [] <$> simpleTerm <* char '.'
      , fmap RuleOp $ Rule <$ string "{(" <*> sepBy complexTerm (string ", ")
          <* string ") => " <*> simpleTerm <* string "}."
      , QueryOp . Query <$ string "(" <*> sepBy complexTerm (string ", ")
          <* string ")?"
      , QuitOp <$ string "quit!"
      , NoOp <$ eof
      , NoOp <$ char '%' <* skipMany (satisfy $ const True)
      ]

type RenameMap = Map String Int
type RenamerT = StateT Int

evalRenamerT :: Monad m => RenamerT m a -> m a
evalRenamerT = flip State.evalStateT 0

rename :: (Monad m, Traversable t) => t String -> RenamerT m (t Int, RenameMap)
rename t = flip State.runStateT Map.empty $ forM t $ \k -> do
  m <- State.gets $ Map.lookup k
  case m of
    Just i -> return i
    Nothing -> do
      i <- lift $ State.state $ \seed -> (seed, seed + 1)
      State.modify $ Map.insert k i
      return i

type Term = SimpleTerm Int
type UnificationT = StateT (Map Term Term)

evalUnificationT :: Monad m => UnificationT m a -> m a
evalUnificationT = flip State.evalStateT Map.empty

find :: Monad m => Term -> UnificationT m Term
find (Relational name ts) = Relational name <$> mapM find ts
find t = do
  m <- State.gets $ Map.lookup t
  case m of
    Nothing -> return t
    Just p
      | p == t -> return t
      | otherwise -> do
        root <- find p
        State.modify $ Map.insert t root
        return root

unify :: Monad m => Term -> Term -> UnificationT m Bool
unify i j = do
  p <- find i
  q <- find j
  if p == q then return True else do
  case (p, q) of
    (Variable v, _) -> link v q
    (_, Variable v) -> link v p
    (Relational pname ps, Relational qname qs)
      | pname /= qname || length ps /= length qs -> return False
      | otherwise -> andM $ zipWith unify ps qs
  where
  link v p
    | elem v p = return False  -- occurs check
    | otherwise = State.modify (Map.insert (Variable v) p) >> return True

same :: Monad m => Term -> Term -> UnificationT m Bool
same i j = (==) <$> find i <*> find j

newtype Result = Result (Map String Term)

instance Show Result where
  show (Result result)
    | Map.null result = "SAT"
    | otherwise = "SAT:\n=====" ++ concat
      [ "\n#" ++ v ++ " := " ++ show term
      | (v, term) <- Map.assocs result
      ]

type Assertion = (Term, Term)
type Watson = RWST
  ([Rule String], RenameMap)
  (Endo [Result])
  ([Term], [Assertion])
  (UnificationT (RenamerT Identity))

local :: Watson a -> Watson a
local f = do
  i <- get
  j <- lift State.get
  ret <- f
  lift $ State.put j
  put i
  return ret

checkAssertions :: Watson Bool
checkAssertions = do
  assertions <- gets snd
  andM $ map (lift . fmap not . uncurry same) assertions

simplify :: [ComplexTerm Int] -> Watson Bool
simplify terms = do
  modify $ (s++) *** (neq++)
  success <- andM $ map (lift . uncurry unify) eq
  if success then checkAssertions else return False
  where
  s = [i | SimpleTerm i <- terms]
  eq = [(i, j) | EqualityAssertion i j <- terms]
  neq = [(i, j) | NonEqualityAssertion i j <- terms]

addResult :: Watson ()
addResult = do
  renameMap <- asks snd
  result <- mapM (lift . find . Variable) renameMap
  tell $ Endo (Result result:)

subtitude :: Term -> Rule String -> Watson Bool
subtitude term rule = do
  (Rule premises conclusion, _) <- lift $ lift $ rename rule
  success <- lift $ unify term conclusion
  if success then simplify premises else return False

prove :: Watson ()
prove = do
  terms <- gets fst
  case terms of
    [] -> addResult
    (term:_) -> do
      modify $ first tail
      rules <- asks fst
      forM_ rules $ \rule -> local $ do
        success <- subtitude term rule
        when success prove

solve :: [Rule String] -> Query String -> [Result]
solve rules query = appEndo results []
  where
  ((), results) = runIdentity $ evalRenamerT $ do
    (Query q, renameMap) <- rename query
    evalUnificationT $
      evalRWST (simplify q >> prove) (rules, renameMap) ([], [])

main :: IO ()
main = do
  ops <- lines <$> getContents
  State.evalStateT (process ops) []
  where
  process :: [String] -> StateT [Rule String] IO ()
  process [] = return ()
  process (op:ops) = case read op of
    RuleOp rule -> do
      State.modify $ (rule:)
      liftIO $ putStrLn "Ok."
      process ops
    QueryOp query -> do
      rules <- State.gets reverse
      let results = solve rules query
      liftIO $ case results of
        [] -> putStrLn "UNSAT"
        _ -> mapM_ print results
      liftIO $ putStrLn "Ready."
      process ops
    QuitOp -> liftIO $ putStrLn "Bye."
    NoOp -> process ops
