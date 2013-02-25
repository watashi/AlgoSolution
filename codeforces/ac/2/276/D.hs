import Control.Applicative
import Data.Bits

gao :: Int -> (Integer, Integer) -> (Integer, Integer) -> Integer
gao p r1 r2
  | r1 == (0, mm) = mm
  | r2 == (0, mm) = mm
  | otherwise     = maximum $ [u1 `xor`  u2 `xor` gao (p - 1) w1 w2 |
      (u1, v1) <- f r1, (u2, v2) <- f r2, let w1 = g v1, let w2 = g v2]
  where
    mm = bit (p + 1) - 1
    b = bit p
    m = b - 1
    f (x, y) = filter (uncurry (<=) . snd) [
      (0, (x, min y m)), (b, (max x b, y))]
    g (x, y) = (x .&. m, y .&. m)

main :: IO ()
main = do
  [l, r] <- map read <$> words <$> getLine
  print $ gao 100 (l, r) (l, r)
