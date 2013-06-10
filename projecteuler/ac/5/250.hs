import Control.DeepSeq
import Data.List
import Data.Int
import ProjectEuler.NumberTheory.Modular

main :: IO ()
main = do
  let zero = take 250 $ 1: repeat 0
      set = [powMod i i 250 | i <- [1 .. 250250]]
      dp = foldl' f zero set
      f a d = let (l, r) = splitAt (250 - d) a in force $ zipWith (+%) a $ r ++ l
      infixl 6 +%
      a +% b = if c >= m then c - m else c
        where
          c = a + b
          m = (10::Int64) ^ (16::Int)
  print $ pred $ head $ dp
