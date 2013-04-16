{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Applicative
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

main :: IO ()
main = do
  (n:m:a) <- map readInt . C.words <$> C.getContents
  let s = maximum $ map length $ group $ sort a
      ans = if m == n - 1 then
              if s == 2 then "bus"
              else if s == n - 1 then "star"
              else "unknown"
            else if m == n then
              if s == 2 then "ring"
              else "unknown"
            else "unknown"
  putStrLn $ ans ++ " topology"
