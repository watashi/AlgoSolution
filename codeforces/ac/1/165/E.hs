{-# OPTIONS_GHC -O2 -optc-O3 -fignore-asserts #-}
import Control.Monad
import Control.Monad.ST
import Data.Array.Unboxed
import Data.Array.ST
import Data.Bits
import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao a = map ((c!) . xor m) a
  where
    n = 22
    m = 2 ^ n - 1
    c = runSTUArray gao' where
      gao' = do
        x <- newArray (0, m) $ -1 :: ST s (STUArray s Int Int)
        forM_ a $ \i -> do
          writeArray x i i
        forM_ [0 .. m] $ \i -> do
          e <- liftM (head . (++[-1]) . filter (>0)) $ mapM (readArray x) $ i:
            [xor i j | j <- map (shiftL 1) [0 .. n - 1], i .&. j /= 0]
          writeArray x i e
        return x

main = do
  C.getLine
  a <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
  putStrLn $ unwords $ map show $ gao a
