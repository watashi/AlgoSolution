import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  (h:t) <- fmap (reverse . map (fst . fromJust . C.readInt) . tail . C.words) C.getContents
  let (x, y) = foldl gao (h, "+") t
  putStrLn $ if x >= 0 then y else map (\i -> if i == '+' then '-' else '+') y
  where
    gao (x, s) y
      | x + y <= y  = (x + y, '+': s)
      | otherwise   = (x - y, '-': s)
