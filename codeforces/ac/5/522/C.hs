{-# LANGUAGE ScopedTypeVariables #-}
import Control.Applicative
import Control.Monad
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  (re:_) <- readInts
  replicateM_ re $ do
    _ <- readInts
    (m:n:_) <- readInts
    (a :: UArray Int Int) <- listArray (1, n) <$> readInts
    b <- replicateM (m-1) $ do
      (i:j:_) <- readInts
      return (i, j)
    let (x, y) = span ((==0) . snd) b
        zx = length $ filter ((==0) . fst) x
        zy = length $ filter ((==0) . fst) b
        cx = accum (-) a [(i, 1) | (i, _) <- x, i /= 0]
        cy = accum (-) cx [(i, 1) | (i, _) <- y, i /= 0]
        v
          | null y = 0
          | otherwise = minimum [c | (i, c) <- assocs cx, cx!i == cy!i]
        f i = (cx!i <= zx && cx!i == cy!i) || cy!i <= zy - v
    putStrLn [if f i then 'Y' else 'N' | i <- [1..n]]
  where
  readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine
