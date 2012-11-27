import Control.Monad
import Data.Array
import Data.Maybe
import Data.Int
import qualified Data.ByteString.Char8 as C

main = do
  [n, m] <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
  s <- replicateM n C.getLine
  case solve n m s of
    Nothing -> putStrLn "Never"
    Just ans -> print ans

solve n m s = gao (1, 1, 1, True, 2) (0 :: Int64)
  where
  a = listArray (1, n) $ map (\i -> C.concat [C.pack "#", C.take m i, C.pack "#"]) s
  c i j = C.index (a!i) j
  gao (k, l, r, dir, ttl) ans
    | k >= n           = Just ans
    | c (k+1) p == '.' = gao (k + 1, p, p, dir, 2) $ ans + 1
    | ttl < 0          = Nothing
    | otherwise        =
      case c k q of
        '.' -> gao (k, l', r', dir, 2) $ ans + 1
        '+' -> gao (k, l', r', not dir, 2) $ ans + 1 + fromIntegral (r - l)
        '#' -> gao (k, l, r, not dir, ttl - 1) $ ans + 1 + fromIntegral (r - l)
    where
      (p, q, l', r') = ans `seq`
        if dir
          then (r, r + 1, l, r + 1)
          else (l, l - 1, l - 1, r)

{-
C.take m i  -- '\r'
ans `seq`   --  Runtime error on test 8
-}
