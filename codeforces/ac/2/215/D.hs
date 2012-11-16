{-# OPTIONS_GHC -O2 -optc-O3 -fignore-asserts #-}
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao n [] = 0
gao n (a:b:x:y:t) = s + r
  where
    c = b - a
    m = (n + c - 1) `div` c
    r = gao n t
    s
      | c <= 0    = x * n + y
      | m == 1    = y
      | otherwise = minimum [x * n + y, m * y, (n - (m - 2) * c) * x + (m - 1) * y]

main = do
  (n:m:a) <- fmap (map (fromIntegral . fst . fromJust . C.readInt) . C.words) C.getContents
  print $ gao m a
