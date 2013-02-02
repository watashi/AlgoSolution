import Control.Monad
import qualified Data.IntMap as M

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- fmap read getLine
    let ans = minimum [d i + d j |
          i <- takeWhile ((<=n) . (^(2::Int))) [1 ..],
          let (j, k) = divMod n i,
          k == 0]
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
    inf = 10000001 :: Int
    d k = min k $ M.findWithDefault k k m
    m = M.fromListWith min $ [(k, v) |
      (v, a) <- zip [2 ..] $ takeWhile (not . null . drop 2) $ iterate gen [1, 2, 1],
      k <- a]
    gen a = takeWhile (<inf) $ zipWith (+) (0:a) $ a ++ [0]
