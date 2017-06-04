{-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Arrow
import Control.Monad
import Data.Bits
import Data.List

data Tree
  = Bin !Bool Tree Tree
  | Tip !Bool

instance Read Tree where
  readsPrec _ s = bin s ++ tip s
    where
    readCell t = [(i == "X", j) | (i, j) <- lex t, i == "X" || i == "."]
    bin s0 = do
      ("(", s1) <- lex s0
      (l, s2) <- reads s1
      (b, s3) <- readCell s2
      (r, s4) <- reads s3
      (")", s5) <- lex s4
      return (Bin b l r, s5)
    tip = map (first Tip) <$> readCell

instance Show Tree where
  showsPrec _ t = case t of
    Bin b l r -> showParen True $
      shows l . showChar ' ' . showCell b . showChar ' ' . shows r
    Tip b -> showCell b
    where
    showCell b = showChar $ if b then 'X' else '.'

getCell :: Tree -> Bool
getCell (Bin b _ _) = b
getCell (Tip b) = b

path :: String -> Tree -> Tree
path s t = foldl' (\(Bin _ l r) c -> if c == '<' then l else r) t s

gen :: Int -> Tree -> Tree
gen rule = go False
  where
  go !p (Bin b l r) = Bin (test p (getCell l) b (getCell r)) (go b l) (go b r)
  go !p (Tip b) = Tip (test p False b False)
  test !p !l !b !r = testBit rule $ foldl (.|.) 0
    [i | (True, i) <- [p, l, b, r] `zip` [8, 4, 2, 1]]

main :: IO ()
main = do
  rule <- readLn
  tree <- readLn
  n <- readLn
  q <- forM [1::Int .. n] $ \i -> do
    (s:p:_) <- words <$> getLine
    return (read s, filter (`elem` "<>") p, i)
  let query = sort $ scanl1 (\(t, _, _) (s, p, i) -> (t + s, p, i)) q
      ans = sort $ gao 0 query $ iterate (gen rule) tree
  mapM_ (print . Tip . snd) ans
  where
  gao n ((s, p, i): q) t = (i, getCell $ path p $ head t'): gao s q t'
    where
    t' = drop (s - n) t
  gao _ [] _ = []
