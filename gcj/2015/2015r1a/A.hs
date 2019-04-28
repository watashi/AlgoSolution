import Control.Monad
import Text.Printf

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    _ <- getLine
    a <- map read . words <$> getLine
    let d = zipWith (\i j -> max 0 $ i - j) a $ tail a
        x = sum d :: Int
        y = sum $ zipWith min (init a) (repeat $ maximum d)
    printf "Case #%d: %d %d\n" ri x y
