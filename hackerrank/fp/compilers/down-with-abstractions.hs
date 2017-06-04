import Control.Monad
import Data.Set (Set)
import qualified Data.Set as Set

data Exp
  = Var (Set String) String
  | App (Set String) Exp Exp
  | Lam (Set String) String Exp
  deriving (Show)

freeVariables :: Exp -> Set String
freeVariables (Var l _) = l
freeVariables (App l _ _) = l
freeVariables (Lam l _ _) = l

isFree :: String -> Exp -> Bool
isFree i j = Set.member i $ freeVariables j

var :: String -> Exp
var i = Var (Set.singleton i) i

app :: Exp -> Exp -> Exp
app i j = App (freeVariables i `Set.union` freeVariables j) i j

lam :: String -> Exp -> Exp
lam i j = Lam (Set.delete i $ freeVariables j) i j

translate :: Exp -> Exp
translate e = case e of
  Lam _ i (App _ j (Var _ k))
    | not (isFree i j) && i == k -> translate j
  Var{} -> e
  App _ i j -> app (translate i) (translate j)
  Lam _ i j
    | not $ isFree i j -> app (var "K") (translate j)
  Lam _ i (Var _ j)
    | i == j -> var "I"
  Lam _ i j@(Lam _ _ k)
    | isFree i k -> translate (lam i $ translate j)
  Lam _ i (App _ j k) -> case (isFree i j, isFree i k) of
    (True, True) -> app2 (var "S") (translate $ lam i j) (translate $ lam i k)
    (True, False) -> app2 (var "C") (translate $ lam i j) (translate k)
    (False, True) -> app2 (var "B") (translate j) (translate $ lam i k)
    _ -> error "impossible1"
  _ -> error "impossible2"
  where
  app2 i j k = app (app i j) k

showSKIBC :: Exp -> String
showSKIBC = ($"") . go False
  where
  go f e = case e of
    Var _ i -> showString i
    App _ i j -> showParen f $ go False i . go True j
    Lam{} -> error "impossible3"

instance Read Exp where
  readsPrec _ s = do
    (i, i') <- lex s
    if i /= "(" then return (var i, i') else do
    (j, j') <- lex i'
    if j /= "\\"
    then do
      (k, k') <- reads i'
      (l, l') <- reads k'
      (")", m') <- lex l'
      return (app k l, m')
    else do
      (k, k') <- varlist j'
      (l, l') <- reads k'
      (")", m') <- lex l'
      return (k l, m')
    where
    varlist x = do
      (i, i') <- lex x
      if i == "." then return (id, i') else do
      (j, j') <- varlist i'
      return (lam i . j, j')

main :: IO ()
main = do
  n <- readLn
  replicateM_ n $ do
    input <- getLine
    putStrLn $ showSKIBC $ translate $ read input
