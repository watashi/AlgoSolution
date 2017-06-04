import Control.Applicative
import Control.Monad
import Data.Array.Unboxed
import Data.List
import qualified Data.ByteString.Char8 as C

bsearch :: (Int -> Bool) -> Int -> Int -> Int
bsearch f = go
  where
  go lo hi
    | lo == hi = hi
    | f mi = go lo mi
    | otherwise = go (mi+1) hi
    where
    mi = lo + (hi - lo) `quot` 2

main :: IO ()
main = do
  (n:input) <- fmap (map readInt . C.words) C.getContents
  let (a, _:q) = splitAt n input
      s :: UArray Int Int
      s = listArray (0, n) $ scanl (+) 0 $ sortBy (flip compare) a
      gao x = bsearch (\i -> s!i >= x) 0 (n+1)
  forM_ q $ \i ->
    print $ let k = gao i in if k > n then -1 else k
  where
  readInt s = let Just (i, _) = C.readInt s in i