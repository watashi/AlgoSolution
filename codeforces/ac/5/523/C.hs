import Control.Applicative
import Control.Monad
import Data.Function
import qualified Data.ByteString as B

gao :: B.ByteString -> B.ByteString -> Maybe Int
gao a b
  | B.null a = Just $ B.length b
  | B.null b || B.null b' = Nothing
  | otherwise = gao (B.tail a) (B.tail b')
  where
  b' = B.dropWhile (/= B.head a) b

main :: IO ()
main = do
  a <- chomp <$> B.getLine
  b <- chomp <$> B.getLine
  let n = B.length b
      x = gao a b
      y = (gao `on` B.reverse) a b
  print $ case liftM2 (\i j -> i + j - n) x y of
    Just k | k >= 0 -> k + 1
    _ -> 0
  where
  chomp s
    | B.null s || B.last s /= 13 = s
    | otherwise = B.init s
