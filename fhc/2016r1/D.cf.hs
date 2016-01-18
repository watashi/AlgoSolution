{-# LANGUAGE MultiWayIf #-}

import Control.Applicative
import Control.Monad
import Data.Array
import Data.Bits
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

subset :: Int -> [Int]
subset n = a!n
  where
  a = listArray (0, 65535) [gao i | i <- [0 ..]]
  gao i
    | popCount c == 1 = go i []
    | otherwise = []
    where
    c = popCount i
    go 0 ret = ret
    go j ret = go (i .&. (j - 1)) $
      if popCount j * 2 == c then j: ret else ret

merge :: (Int, Int) -> (Int, Int) -> (Int, Int)
(a, b) `merge` (c, d) = (a .|. c, b .|. d)

solve :: (Int, [[Int]]) -> [(Int, Int)]
solve (n, a) = [(place $ best i, place $ worst i) | i <- [0 .. n - 1]]
  where
  k = ctz n
  m = 2 ^ n
  place level
    | level < k = succ $ 1 `unsafeShiftL` (k - level - 1)
    | otherwise = 1

  w = listArray (0, n-1) $ map (foldr1 $ \i j -> j `unsafeShiftL` 1 .|. i) a
  dp = listArray (1, m-1) $ map gao [1 ..]
  gao z | popCount z == 1 = (z, 0)
  gao z = foldr merge (0, 0)
    [ if
        | jsLose == 0 -> (jsWin, bit i)
        | jsWin == 0 -> (bit i, jsLose)
        | otherwise -> (bit i, jsLose) `merge` (jsWin, bit i)
    | x <- subset z
    , let y = z `xor` x
    , let (dpx, dpy) = (fst $ dp!x, fst $ dp!y)
    , let (is, js)
            | popCount dpx <= popCount dpy = (dpx, dpy)
            | otherwise = (dpy, dpx)
    , i <- bits is
    , let wi = w!i
    , let jsLose = js .&. wi
    , let jsWin = js .&. complement wi
    ]

  pos = accumArray merge (0, 0) (0, k)
    [ (level, outcomes)
    | (competitors, outcomes) <- assocs dp
    , let size = popCount competitors
    , popCount size == 1
    , let level = ctz size
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

  ctz :: Int -> Int
  ctz i = popCount $ complement i .&. (i - 1)

  bits :: Int -> [Int]
  bits 0 = []
  bits i = let j = i .&. (i - 1) in ctz (i `xor` j): bits j

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    n <- readInt <$> C.getLine
    a <- replicateM n $ map readInt . C.words <$> C.getLine
    let ans = solve (n, a)
    putStrLn $ "Case #" ++ show ri ++ ": "
    forM ans $ \(best, worst) ->
      putStrLn $ show best ++ " " ++ show worst
