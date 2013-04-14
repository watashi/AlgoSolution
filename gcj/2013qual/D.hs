import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import qualified Data.IntMap as M

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    [_, n] <- getArray
    a <- fmap (`zip` repeat 1) getArray
    b <- fmap (listArray (0, n - 1)) $ replicateM n $ do
      (k:_:v) <- getArray
      return $ ((k, -1):) $ zip v $ repeat (1::Int)
    let m = pred $ bit n
        dp = listArray (0, m) [if i < m then f i else n | i <- [0::Int .. m]]
        f i =
          if minimum (M.elems c) < 0
            then -1
            else head $ (++[-1]) $ [j |
              j <- q,
              M.findWithDefault 0 (fst $ head $ b!j) c > 0,
              let k = setBit i j,
              dp!k >= 0]
          where
            c = M.fromListWith (+) $ concat $ a: [b!j | j <- p]
            (p, q) = partition (testBit i) [0 .. n - 1]
        g i = if i == m then [] else let j = dp!i in j: g (setBit i j)
    putStr $ "Case #" ++ show ri ++ ": "
    if dp!0 < 0
      then putStrLn "IMPOSSIBLE"
      else putStrLn $ unwords $ map (show . succ) $ g 0
  where
    getArray :: IO [Int]
    getArray = fmap (map read . words) $ getLine
