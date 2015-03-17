{-# LANGUAGE MultiWayIf #-}
import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  n <- readInt <$> C.getLine
  a <- replicateM n $ do
    [w, h] <- map readInt . C.words <$> C.getLine
    return (w, h)
  let (h1, h2) = flip foldl1' ((0, 0): a) $ \k@(i, j) (_, h) -> if
        | h > i -> (h, i)
        | h > j -> (i, h)
        | otherwise -> k
      sw = sum $ map fst a
      ans = [(sw - w) * (if h /= h1 then h1 else h2) | (w, h) <- a]
  putStrLn $ unwords $ map show ans
  where
  readInt = fst . fromJust . C.readInt
