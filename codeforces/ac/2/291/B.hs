import Control.Applicative
import Data.Char
import qualified Data.ByteString.Char8 as C

parse :: C.ByteString -> [C.ByteString]
parse s =
  case C.uncons s of
    Nothing       -> []
    Just (' ', t) -> parse $ C.dropWhile (==' ') t
    Just ('"', t) -> let (i, j) = C.span (/='"') t in (i:) $ parse $ C.tail j
    _             -> let (i, j) = C.span (/=' ') s in (i:) $ parse j

main :: IO ()
main = do
  s <- fmap (C.map (\i -> if isSpace i then ' ' else i)) C.getLine  -- WTF
  C.putStr $ C.unlines $ map (('<' `C.cons`) . (`C.snoc` '>')) $ parse s
