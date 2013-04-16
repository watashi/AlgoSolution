import Control.Applicative
import Data.Maybe
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

main :: IO ()
main = do
  a <- pairs . tail . map readInt . C.words <$> C.getContents
  let (t, c, maxc) = foldl gao (0, 0, 0) a
  print $ t + c
  print $ maxc
  where
    gao (t, c, maxc) (tt, cc) = let c' = cc + max 0 (c - (tt - t)) in (tt, c', max maxc $ c')
