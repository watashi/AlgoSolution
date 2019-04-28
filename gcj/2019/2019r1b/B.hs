import Control.Monad
import Data.Bits
import System.IO

main :: IO ()
main = do
  (re:_) <- map read . words <$> getLine
  replicateM_ re $ do
    print 50  -- [50,25,16,12,10,8]
    hFlush stdout
    ans50 <- readLn
    print 200 -- [200,100,66,50,40,33]
    hFlush stdout
    ans200 <- readLn
    let a6 = ans200 `shiftR` (200 `quot` 6) .&. 0x7f :: Int
        a5 = ans200 `shiftR` (200 `quot` 5) .&. 0x7f
        a4 = ans200 `shiftR` (200 `quot` 4) .&. 0x7f
        ans50' = ans50 - sum
          [ i `shiftL` (50 `quot` j)
          | (i, j) <- [a4, a5, a6] `zip` [4, 5, 6]
          ]
        a3 = ans50' `shiftR` (50 `quot` 3) .&. 0x7f
        a2 = ans50' `shiftR` (50 `quot` 2) .&. 0x7f
        a1 = ans50' `shiftR` (50 `quot` 1) .&. 0x7f
    putStrLn $ unwords $ map show [a1, a2, a3, a4, a5, a6]
    hFlush stdout
    void getLine

