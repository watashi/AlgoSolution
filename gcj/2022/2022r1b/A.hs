{-# LANGUAGE BangPatterns #-}
import Control.Monad
import qualified Data.Sequence as Seq
import qualified Data.ByteString.Char8 as C
import Text.Printf

gao :: Int -> Int -> Seq.Seq Int -> Int
gao !n !m s = case s of
  Seq.Empty -> n
  l Seq.:<| ls
    | l <= r -> gao (n + fromEnum (l >= m)) (max l m) ls
    | otherwise -> gao (n + fromEnum (r >= m)) (max r m) rs
  where
    rs Seq.:|> r = s

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    _ <- C.getLine
    ds <- map readInt . C.words <$> C.getLine
    printf "Case #%d: %d\n" ri $ gao 0 0 $ Seq.fromList ds
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
