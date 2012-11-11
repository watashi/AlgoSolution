import Control.Arrow
import Data.List
import Data.Maybe
import Data.Ord
import qualified Data.ByteString.Char8 as C

parse s =
  case C.readInt s of
    Just (l, s') ->
      case C.readInt (C.tail s') of
        Just (r, _) ->
          (l, r)

gao a = if r < r' then -1 else k + 1
  where
    (l, r) = minimumBy (comparing $ second negate) a
    k = fromJust $ elemIndex (l, r) a
    r' = maximum $ map snd a

main = do
  a <- fmap (map parse . tail . C.lines) C.getContents
  print $ gao a
