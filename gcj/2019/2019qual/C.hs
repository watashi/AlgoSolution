import Control.Monad
import Data.List
import qualified Data.Map as Map

main :: IO ()
main = do
  re <- readLn
  forM_ [(1 :: Int) .. re] $ \ri -> do
    _ <- getLine
    x@(x0:_) <- map read . words <$> getLine
    -- note the case x!!0 == x!!1
    let (xl, xr@(x1: _)) = span (==x0) x
        y1 = gcd x0 x1 :: Integer
        y0 = x0 `quot` y1
        yr = y1: zipWith quot xr yr
        yl = reverse $ take (length xl) $ cycle [y0, y1]
        y = yl ++ yr
        m = Map.fromList $ (map head $ group $ sort y) `zip` ['A' .. 'Z']
    putStrLn $ "Case #" ++ show ri ++ ": " ++ map (m Map.!) y
