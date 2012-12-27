{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Control.Monad
import Data.Array.Unboxed
import Data.Function
import Data.List
import Data.Maybe
import Data.Ord
import System.Exit
import Text.Printf
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

uniq :: Ord a => [a] -> [a]
uniq = map head . group . sort

groupBy' :: Ord b => (a -> b) -> [a] -> [[a]]
groupBy' f = groupBy ((==) `on` f) . sortBy (comparing f)

type Arr = UArray Int Int

listArray' :: [Int] -> Arr
listArray' a = listArray (0, length a - 1) a

lowerBound :: Arr -> Int -> Int
lowerBound a x = go s $ t + 1
  where
    (s, t) = bounds a
    go l r
      | l == r    = l
      | otherwise = if a!m >= x then go l m else go (m + 1) r
      where
        m = (l + r) `div` 2

gao :: Arr -> [Int] -> Maybe [Int]
gao a xs = go (scanl1 (+) xs) [s]
  where
    (s, t) = bounds a
    go [] is = Just $ reverse is
    go (x:y) is =
      if i <= t && a!i == x
        then go y $ succ i:is
        else Nothing
      where
        i = lowerBound a x

data Node
  = Empty
  | Branch Int Int Arr Node Node

build :: Int -> Int -> [(Int, Int)] -> Node
build _ _ [] = Empty
build l r a = Branch l r (listArray' $ map snd a) bl br
  where
    m = (l + r) `div` 2
    (al, ar) = partition ((<m) . fst) a
    bl = build l m al
    br = build m r ar

query :: Node -> (Int, Int) -> (Int, Int) -> Int
query root (xl, xr) (yl, yr) = go root
  where
    go Empty = 0
    go (Branch l r a bl br)
      | l' == l && r' == r  = lowerBound a yr - lowerBound a yl
      | l' < r'             = go bl + go br
      | otherwise           = 0
      where
        l' = max l xl
        r' = min r xr

gen :: [Int] -> [[Int]]
gen [] = [[]]
gen a = concat [map (sum i:) $ gen j | (i, j) <- choose (3::Int) a [] []]
  where
    choose 0 k     i j = [(i, j ++ k)]
    choose _ []    _ _ = []
    choose n (h:t) i j = choose (n - 1) t (h:i) j ++ choose n t i (h:j)

main :: IO ()
main = do
  (n:input) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let (xy, z) = splitAt (2 * n) input

      (x, y) = unzip $ pairs xy
      xs = listArray' $ uniq x
      ys = listArray' $ uniq y
      p = [(lowerBound xs i, lowerBound ys j) | (i, j) <- pairs xy]

      countBy f = scanl1 (+) . map length . groupBy' f
      q = uniq $ gen z
      cx = listArray' $ countBy fst p
      qx = catMaybes $ map (gao cx) $ q
      cy = listArray' $ countBy snd p
      qy = catMaybes $ map (gao cy) $ q

      tree = build 0 (succ $ maximum $ map fst p) $ sortBy (comparing snd) p
      r = sort z

  forM_ (groupBy' (!!1) qx) $ \qx' -> do
    forM_ (groupBy' (!!1) qy) $ \qy' -> do
      when (query tree (0, qx'!!0!!1) (0, qy'!!0!!1) `elem` r) $ do
        forM_ qx' $ \i -> do
          forM_ qy' $ \j -> do
            let r' = [query tree rx ry | rx <- zip i $ tail i, ry <- zip j $ tail j]
            when (sort r' == r) $ do
              forM_ [xs!(i!!1), xs!(i!!2), ys!(j!!1), ys!(j!!2)] $ \k -> do
                printf "%.10f\n" (fromIntegral k - 0.5 :: Double)
              exitSuccess

  putStrLn "-1"
