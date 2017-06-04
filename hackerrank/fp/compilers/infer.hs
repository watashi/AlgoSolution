import Control.Monad
import Control.Monad.Trans.Class
import Control.Monad.Trans.State.Strict
import Data.Char
import Data.Functor.Identity
import Data.List (intersperse, sort)
import Data.Map.Strict (Map)
import qualified Data.Map.Strict as Map
import qualified Data.Set as Set
import Debug.Trace
import Text.ParserCombinators.ReadP

data Type
  = TypeVar Int
  | TypeApp String [Type]
  deriving (Eq, Ord)

instance Show Type where
  showsPrec d t = case t of
    TypeVar i -> showChar '#' . shows i
    TypeApp "->" (i:j:_) -> showParen (d > 0) $
      showsPrec 1 i . showString " -> " . shows j
    TypeApp "()" ts -> showParen True $ csv ts
    TypeApp name [] -> showString name
    TypeApp name ts -> showString name . showChar '[' . csv ts . showChar ']'
    where
    csv = foldr1 (.) . intersperse (showString ", ") . map shows

data QuantifiedType
  = QuantifiedType [Type] Type

instance Show QuantifiedType where
  show (QuantifiedType quantifiers t) = prefix ++ show t
    where
    prefix = case quantifiers of
      [] -> ""
      _ -> "forall[" ++ unwords (map show quantifiers) ++ "] "

typeId :: String -> Type
typeId i = TypeApp i []

apps :: [Type] -> Type
apps = foldr1 (\i j -> TypeApp "->" [i, j])

tuple :: [Type] -> Type
tuple [t] = t
tuple ts = TypeApp "()" ts

universe :: Type -> [Type]
universe t = case t of
  TypeApp _ ts -> t: concatMap universe ts
  _ -> [t]

transformM :: Monad m => (Type -> m Type) -> Type -> m Type
transformM f = go
  where
  go (TypeApp name args) = f . TypeApp name =<< mapM go args
  go x = f x

type TypeChecker = StateT (Map Type Type) (State Int)

find :: Type -> TypeChecker Type
find (TypeApp name args) = TypeApp name <$> mapM find args
find t = do
  m <- gets $ Map.lookup t
  case m of
    Nothing -> do
      modify' $ Map.insert t t
      return t
    Just p
      | t == p -> return t
      | otherwise -> do
        root <- find p
        modify' $ Map.insert t root
        return root

unify :: Type -> Type -> TypeChecker ()
unify i j = do
  p <- find i
  q <- find j
  when (p /= q) $ do
    case (p, q) of
      (TypeVar{}, _) -> modify $ Map.insert p q
      (_, TypeVar{}) -> modify $ Map.insert q p
      (TypeApp pname pargs, TypeApp qname qargs)
        | pname == qname && length pargs == length qargs ->
          zipWithM_ unify pargs qargs
        | otherwise -> error $ show (p, q)

newvar :: TypeChecker Type
newvar = do
  i <- lift $ state $ \s -> (s, s + 1)
  return $ TypeVar i

specialize :: QuantifiedType -> TypeChecker Type
specialize (QuantifiedType quantifiers t) = do
  vars <- replicateM (length quantifiers) newvar
  let renamed = Map.fromList $ quantifiers `zip` vars
      rename i = return $ Map.findWithDefault i i renamed
  return $ runIdentity $ transformM rename t

generalize :: Type -> TypeChecker QuantifiedType
generalize t = do
  unified <- find t
  let (renamed, quantifiers) = runState (transformM rename unified) Map.empty
  return $ QuantifiedType (sort $ Map.elems quantifiers) renamed
  where
  rename (TypeVar i) = do
    m <- gets $ Map.lookup i
    case m of
      Just j -> return j
      Nothing -> do
        n <- gets $ Map.size
        let j = typeId [chr $ ord 'a' + n]
        modify $ Map.insert i j
        return j
  rename i = return i

evalTypeChecker :: TypeChecker a -> a
evalTypeChecker f = evalState (evalStateT f Map.empty) 0

type Env = Map String QuantifiedType

globalEnv :: Env
globalEnv = Map.fromList
  [ add "head"          [a]     [list a, a]
  , add "tail"          [a]     [list a, list a]
  , add "nil"           [a]     [list a]
  , add "cons"          [a]     [tuple [a, list a], list a]
  , add "cons_curry"    [a]     [a, list a, list a]
  , add "map"           [a, b]  [tuple [apps [a, b], list a], list b]
  , add "map_curry"     [a, b]  [apps [a, b], list a, list b]
  , add "one"           []      [int]
  , add "zero"          []      [int]
  , add "succ"          []      [int, int]
  , add "plus"          []      [tuple [int, int], int]
  , add "eq"            [a]     [tuple [a, a], bool]
  , add "eq_curry"      [a]     [a, a, bool]
  , add "not"           []      [bool, bool]
  , add "true"          []      [bool]
  , add "false"         []      [bool]
  , add "pair"          [a, b]  [tuple [a, b], pair a b]
  , add "pair_curry"    [a, b]  [a, b, pair a b]
  , add "first"         [a, b]  [pair a b, a]
  , add "second"        [a, b]  [pair a b, b]
  , add "id"            [a]     [a, a]
  , add "const"         [a, b]  [a, b, a]
  , add "apply"         [a, b]  [tuple [apps [a, b], a], b]
  , add "apply_curry"   [a, b]  [apps [a, b], a, b]
  , add "choose"        [a]     [tuple [a, a], a]
  , add "choose_curry"  [a]     [a, a, a]
  ]
  where
  add :: String -> [Type] -> [Type] -> (String, QuantifiedType)
  add name quantifiers t = (name, QuantifiedType quantifiers $ apps t)

  a = TypeVar (-1)
  b = TypeVar (-2)
  bool = typeId "bool"
  int = typeId "int"
  list t = TypeApp "list" [t]
  pair x y = TypeApp "pair" [x, y]

data Expr
  = Let String Expr Expr
  | Fun [String] Expr
  | App Expr Expr
  | Tup [Expr]
  | Var String
  deriving (Show)

instance Read Expr where
  readsPrec _ = readP_to_S expr
    where
    ident = (:)
      <$> satisfy (\c -> isAlpha c || c == '_')
      <*> munch (\c -> isAlphaNum c || c == '_')
    expr = foldr1 (<++)
      [ Let <$ string "let " <*> ident <* string " = " <*> expr
          <* string " in " <*> expr
      , Fun <$ string "fun " <*> (sepBy1 ident $ char ' ')
          <* string " -> " <*> expr
      , app <$> many1 simpleExpr
      ]
    simpleExpr = foldr1 (<++)
      [ Var <$> ident
      , tup <$ char '(' <*> (sepBy1 expr $ string ", ") <* char ')'
      ]

    tup [e] = e
    tup es = Tup es
    app args = foldl1 App args

typeCheck :: Expr -> QuantifiedType
typeCheck e = evalTypeChecker $ do
  t <- go globalEnv e
  generalize =<< find t
  where
  go :: Env -> Expr -> TypeChecker Type
  go env expr = do
    t <- case expr of
      Let i e1 e2 -> do
        t1 <- go env e1
        bounded <- mapM find [u | QuantifiedType [] u <- Map.elems env]
        let quantifiers = Set.toList $
              Set.fromList [u | u@TypeVar{} <- universe t1] `Set.difference`
              Set.fromList [u | u@TypeVar{} <- concatMap universe bounded]
        go (Map.insert i (QuantifiedType quantifiers t1) env) e2
      Fun i e1 -> do
        v <- replicateM (length i) newvar
        let args = Map.fromList $ i `zip` map (QuantifiedType []) v
        t1 <- go (args `Map.union` env) e1
        return $ apps [tuple v, t1]
      App e1 e2 -> do
        t1 <- go env e1
        t2 <- go env e2
        v <- newvar
        unify t1 $ apps [t2, v]
        return v
      Tup e1 -> tuple <$> mapM (go env) e1
      Var i -> case Map.lookup i env of
        Nothing -> error $ "not in scope: " ++ i
        Just v -> specialize v
    ret <- find t
    traceM $ show expr
    traceM $ "  " ++ show ret
    return ret

main :: IO ()
main = do
  e <- readLn
  print $ typeCheck e
