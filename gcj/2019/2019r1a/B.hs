import Control.Monad
import Data.List
import System.IO

extGcd :: Integer -> Integer -> (Integer, Integer, Integer)
extGcd a 0 = (a, 1, 0)
extGcd a b = (g, x, y - a `quot` b * x)
  where
  (g, y, x) = extGcd b (a `rem` b)

modInv :: Integer -> Integer -> Integer
modInv a m = x `mod` m
  where
  (1, x, _) = extGcd a m

main :: IO ()
main = do
  (re:_) <- map read . words <$> getLine
  replicateM_ re $ do
    forM_ ps $ \p ->
      putStrLn $ unwords $ map show $ replicate 18 p
    hFlush stdout
    input <- forM ps $ \p -> do
      s <- sum . map read . words <$> getLine
      return (s `mod` p, p)
    let gao (a, m) (b, n) = ((a * modInv n m * n + b * modInv m n * m) `mod` (m * n), m * n)
        (ans, _) = foldl1' gao input
    print ans
    hFlush stdout
    _ <- getLine
    return ()
  where
   ps = [3, 4, 5, 7, 11, 13, 17]
