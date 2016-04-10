import Control.Monad
import Data.Function

gen :: Int -> ([String], [Integer])
gen n =
  ( [i ++ (if odd n then ('0':) else id) i | i <- map ('1':) x]
  , [b ^ d + 1 | b <- [2 .. 10]]
  )
  where
  m = n `quot` 2 - 2
  d = n - n `quot` 2
  x = foldM (&) "1" $ replicate m $ \i -> ['0':i, '1':i]

main :: IO ()
main = do
  1 <- read <$> getLine
  (n:j:_) <- map read . words <$> getLine
  let (x, y) = gen n
  putStrLn "Case #1:"
  forM_ (take j x) $ \i -> do
    putStrLn $ unwords $ i: map show y
