import Control.Applicative
import Control.Monad
import Data.Array
import Data.Function (on)
import Data.Graph hiding (path)
import Data.List
import Data.Maybe
import qualified Data.Set as S
import qualified Data.Map as M

isSubGraphConnected :: Graph -> S.Set Int -> Bool
isSubGraphConnected g v = length (components g') <= 1
  where
  vid = M.fromList $ S.elems v `zip` [1..]
  g' = buildG (1, M.size vid) $ catMaybes
    [liftM2 (,) (M.lookup i vid) (M.lookup j vid) | (i, j) <- edges g]

gao :: Array Int String -> Graph -> [String]
gao v g = (v!src:) . gao' [src] . S.fromList . filter (/=src) $ indices v
  where
  src = fst . minimumBy (compare `on` snd) $ assocs v
  gao' _ todo | S.null todo = []
  gao' path todo =
    let ((_, leaf), (_, path')) = minimum
          [ (minimum e, (negate $ length i, i))
          | i <- tail $ inits path
          , let e = [(v!j, j) | j <- g!last i, S.member j todo]
          , not . null $ e
          , isSubGraphConnected g $ todo `S.union` S.fromList i
          ]
    in (v!leaf): gao' (path' ++ [leaf]) (S.delete leaf todo)

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    (n:m:_) <- map read . words <$> getLine
    z <- replicateM n $ getLine
    e <- replicateM m $ do
      (a:b:_) <- map read . words <$> getLine
      return [(a, b), (b, a)]
    let v = listArray (1, n) z
        g = accumArray (flip (:)) [] (1, n) $ concat e
    putStrLn . concat $
      "Case #":
      show ri:
      ": ":
      gao v g
