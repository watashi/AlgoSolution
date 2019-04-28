import Control.Monad
import Text.Printf

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    [c, f, x] <- fmap (map read . words) getLine
    let n = floor $ 2 * x + (1000 :: Double)
        d = [1 / (2 + realToFrac i * f) | i <- [0::Int .. n]]
        t = zipWith (+) (map (x*) d) $ scanl (+) 0.0 $ map (c*) d
    printf "Case #%d: %.8f\n" ri $ minimum t
