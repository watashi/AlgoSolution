import Control.Monad
import Control.Arrow
import qualified Data.IntMap as Map
import Text.Printf
-- import Debug.Trace

gao :: [Int] -> [Int] -> Int
gao add sub = snd $ minimum $ map (first negate) $
  -- traceShowId $
  scanl (\(a, _) (x, b) -> (a + b, x)) (length sub, 0) $
  Map.toList $ Map.fromListWith (+) $
  [(i, 1) | i <- add] ++ [(i, -1) | i <- sub]

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    (p:_:_) <- map read . words <$> getLine
    ds <- replicateM p $ do
      (x:y:z:_) <- words <$> getLine
      return (read x, read y, z)
    let ns = [y + 1 | (_, y, 'N':_) <- ds]
        ss = [y | (_, y, 'S':_) <- ds]
        es = [x + 1 | (x, _, 'E':_) <- ds]
        ws = [x | (x, _, 'W':_) <- ds]
        ansy = gao ns ss
        ansx = gao es ws
    printf "Case #%d: %d %d\n" ri ansx ansy
