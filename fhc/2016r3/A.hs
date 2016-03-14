import Control.Applicative
import Control.Monad
import Data.List
import Text.Printf

newtype Matrix a = Matrix [[a]]
  deriving (Show)

instance Num a => Num (Matrix a) where
  Matrix a + Matrix b = Matrix $ zipWith (zipWith (+)) a b
  Matrix a - Matrix b = Matrix $ zipWith (zipWith (-)) a b
  Matrix a * Matrix b =
    Matrix [[sum $ zipWith (*) i j | j <- transpose b] | i <- a]
  abs = undefined
  signum = undefined
  fromInteger n = Matrix [[fromInteger n, 0], [0, fromInteger n]]
    -- I am cheating here @fromInteger 1@ will be called in 'pow'

solve :: (Int, Double, Double, Double, Double) -> Double
solve (n, ww, wb, lw, lb)
  | n == 1 = ww
  | otherwise = ansx
  where
  wx = max ww wb
  wy = max (1 - ww) (1 - wb)
  lx = max lw lb
  ly = max (1 - lw) (1 - lb)
  firstRound = Matrix [[lw], [1 - lw]]
  middleRound = Matrix [[lx, 1 - ly], [1 - lx, ly]]
  lastRound = Matrix [[wx, 1 - wy], [1 - wx, wy]]
  Matrix [[ansx], [_]] = lastRound * middleRound ^ (n - 2) * firstRound

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    ans <- solve <$> getInput
    printf "Case #%d: %.20f\n" ri ans
  where
  getInput = do
    n <- read <$> getLine
    (ww:wb:_) <- map read . words <$> getLine
    (lw:lb:_) <- map read . words <$> getLine
    return (n, ww, wb, lw, lb)
