import Control.Monad
import Data.Char
import Text.Printf

gen :: [(Char, Char)] -> String -> [(Integer, String, String)]
gen [] s = [(0, reverse s, reverse s)]
gen ((x, y): t) s
  | x == '?' && y == '?' =
      concat [gen (i: t) s | i <- [('0', '1'), ('1', '0'), ('0', '0')]]
  | x == '?' =
      concat [gen ((f y, y): t) s | f <- [pred, id, succ], isDigit $ f y]
  | y == '?' =
      concat [gen ((x, f x): t) s | f <- [pred, id, succ], isDigit $ f x]
  | x < y =
      let a = fill x (fst <$> t) '9'
          b = fill y (snd <$> t) '0'
      in [(read b - read a, a, b)]
  | x > y =
      let a = fill x (fst <$> t) '0'
          b = fill y (snd <$> t) '9'
      in [(read a - read b, a, b)]
  | otherwise =
      gen t (x: s)
  where
  fill current rest replacement =
    reverse (current: s) ++ [if i == '?' then replacement else i | i <- rest]

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    (c:j:_) <- words <$> getLine
    let (_, a, b) = minimum $ gen (c `zip` j) ""
    printf "Case #%d: %s %s\n" ri a b
