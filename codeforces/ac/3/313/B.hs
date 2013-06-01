{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Data.Array.Unboxed
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

main :: IO ()
main = do
  s <- C.getLine
  let a = C.zipWith (\i j -> if i == j then 1 else 0) s $ C.tail s
      b :: UArray Int Int
      b = listArray (1, C.length s) $ scanl (+) 0 a
  q <- fmap (pairs . map readInt . tail . C.words) C.getContents
  putStr $ unlines $ map (\(i, j) -> show $ b!j - b!i) $ q
