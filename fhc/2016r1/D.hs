import Control.Monad
import Control.Parallel.Strategies
import Data.Array
import Data.Bits
import Data.Maybe
import Data.Tuple
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

subset :: Int -> [Int]
subset i = go i
  where
  go 0 = [0]
  go j = j: go (i .&. (j - 1))

merge :: (Int, Int) -> (Int, Int) -> (Int, Int)
(a, b) `merge` (c, d) = (a .|. c, b .|. d)

solve :: (Int, [[Int]]) -> [(Int, Int)]
solve (n, a) = [(place $ best i, place $ worst i) | i <- [0 .. n - 1]]
  where
  k = countTrailingZeros n
  m = 2 ^ n
  place level
    | level < k = succ $ 1 `unsafeShiftL` (k - level - 1)
    | otherwise = 1

  w = listArray ((0, 0), (n-1, n-1)) [j > 0 | i <- a, j <- i]
  dp = listArray (1, m-1) $ map gao [1 ..]
  gao z | popCount z == 1 = (z, 0)
  gao z = foldr merge (0, 0)
    [ (if w!(i, j) then id else swap) (bit i, bit j)
    | x <- subset z
    , let y = z `xor` x
    , popCount x == popCount y
    , i <- filter (testBit . fst $ dp!x) [0 .. n - 1]
    , j <- filter (testBit . fst $ dp!y) [0 .. n - 1]
    ]

  pos = accumArray merge (0, 0) (0, k)
    [ (level, outcomes)
    | (competitors, outcomes) <- assocs dp
    , let size = popCount competitors
    , popCount size == 1
    , let level = countTrailingZeros size
    ]
  best i = maximum
    [ level
    | (level, (winners, _)) <- assocs pos
    , winners `testBit` i
    ]
  worst i = minimum $ k:
    [ level - 1
    | (level, (_, losers)) <- assocs pos
    , losers `testBit` i
    ]

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = runEval $ parList rdeepseq $ map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": "
    forM ans $ \(best, worst) ->
      putStrLn $ show best ++ " " ++ show worst
  where
  getInput = do
    n <- readInt <$> C.getLine
    a <- replicateM n $ map readInt . C.words <$> C.getLine
    return (n, a)
