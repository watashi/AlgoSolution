import Control.Arrow ((***))
import Data.List (sort)

base = 10 ^ 9 :: Int

ok s = (sort $ take 9 s) == "123456789"

dadd :: (Double, Double) -> (Double, Double)
dadd (a, b) = until ((<= fromIntegral base) . snd) (\(a, b) -> (a / 10, b / 10)) (b, a + b)

dok (a, b) = ok $ filter (/= '.') $ show b

iadd :: (Int, Int) -> (Int, Int)
iadd (a, b) = (b, mod (a + b) base)

iok (a, b) = ok $ show b

main = do putStrLn $ show $ (2+) $ length $ takeWhile (not . uncurry (&&) . (dok *** iok)) $ iterate (dadd *** iadd) ((1, 1), (1, 1))

