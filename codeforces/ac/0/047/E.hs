import Data.List (sort)
import Data.Maybe (fromJust)
import qualified Data.ByteString.Char8 as C

readInt = fst . fromJust . C.readInt

readDouble bs =
  if C.null bs'
    then fromIntegral a
    else fromIntegral (a * c + b) / fromIntegral c
  where
    Just (a, bs') = C.readInt bs
    t = C.tail bs'
    b = readInt t
    c = 10 ^ C.length t

pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main = do
  (n':v':input) <- fmap C.words C.getContents
  let n = readInt n'
      v = readInt v'
      (a',(m':z')) = splitAt n input
  let a = map readDouble a'
      m = readInt m'
      z = map readDouble z'
  putStrLn $ unwords $ map show $ concatMap snd $ sort $
    gao n (fromIntegral v) (zip a [0 ..]) $ pairs z

gao :: Int -> Double -> [(Double, Int)] -> [(Double, Double)] -> [(Int, [Double])]
gao n v as zs = gao' (sort as) (sort zs) where
  eps = 1e-8
  g = 9.8
  gao' [] _ = []
  gao' ((a,i):a') z = (i, xy) : gao' a' z' where
    vx = v * cos(a)
    vy = v * sin(a)
    yt x = let t = x / vx in vy * t - g * t * t / 2
    z' = dropWhile (\(x, y) -> y < yt x + eps) z
    xy =
      if null z' || y < -eps
        then [v * v * sin(2 * a) / g, 0]
        else let x = fst $ head z' in [x, y]
      where
        x = fst $ head z'
        y = yt x

{- Time limit exceeded on test 7 -}
{- PS: if yt x < 0 .... WA -}
