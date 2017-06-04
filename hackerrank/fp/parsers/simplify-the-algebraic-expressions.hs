import Control.Applicative hiding (many)
import Control.Arrow (second)
import Control.Monad (replicateM_)
import Data.Char
import Data.Function
import Data.List
import Data.Ratio
import Text.ParserCombinators.ReadP

newtype Polynomial = Polynomial [(Int, Rational)]

mkPolynomial :: [(Int, Rational)] -> Polynomial
mkPolynomial terms = Polynomial
  [ (k, a)
  | i@((k, _): _) <- groupBy ((==) `on` fst) $ sort terms
  , let a = sum $ map snd i
  , a /= 0
  ]

instance Num Polynomial where
  Polynomial a + Polynomial b = mkPolynomial $ a ++ b
  Polynomial a * Polynomial b =
    mkPolynomial $ concat [[(i + j, u * v) | (j, v) <- b] | (i, u) <- a]
  negate (Polynomial a) = Polynomial $ map (second negate) a
  fromInteger a = Polynomial [(0, a % 1)]
  abs = error "Polynomial.abs"
  signum = error "Polynomial.signum"

instance Show Polynomial where
  show (Polynomial a) = foldl' (\i j -> i . showTerm j) h t ""
    where
    (hn, hc): t = reverse a
    h = showCoefficient hc . showVariable hn
    showTerm (n, c)
      | c < 0 = showString " - " . showCoefficient (-c) . showVariable n
      | otherwise = showString " + " . showCoefficient c . showVariable n
    showCoefficient c = case (denominator c, numerator c) of
      (1, 1) -> id
      (1, -1) -> showChar '-'
      (1, n) -> shows n
      _ -> undefined
    showVariable n = case n of
      0 -> id
      1 -> showChar 'x'
      _ -> showString "x^" . shows n

inv :: Polynomial -> Polynomial
inv (Polynomial [(0, p)]) = Polynomial [(0, 1 / p)]
inv p = error $ "inv: " ++ show p

pow :: Polynomial -> Polynomial -> Polynomial
pow a (Polynomial [(0, n)]) | denominator n == 1 = a ^ numerator n
pow _ n = error $ "pow: " ++ show n

polynomial, term, factor, value :: ReadP Polynomial
polynomial = foldl (+) <$> term <*> many (op <*> term)
  where op = (char '+' *> pure id) <++ (char '-' *> pure negate)
term =  foldl1 (<++)
  [ negate <$> (char '-' *> term)
  , foldl (*) <$> factor <*> many (op <*> factor)
  ]
  where op = (char '*' *> pure id) <++ (char '/' *> pure inv) <++ pure id
factor = flip ($) <$> value <*> op
  where op = (char '^' *> (flip pow <$> value)) <++ pure id
value = foldl1 (<++)
  [ char 'x' *> pure (Polynomial [(1, 1)])
  , char '(' *> polynomial <* char ')'
  , fromInteger . read <$> munch1 isDigit
  ]

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    s <- filter (not . isSpace) <$> getLine
    case readP_to_S (polynomial <* eof) s of
      [(p, "")] -> print p
      p -> error $ "main: " ++ show p