{-# OPTIONS -O2 -optc-O3 #-}
module Enumeration (
  subsets,
  combinations,
  slices,
  substrings,
  pairs,

  binarySearchBy,
  mergeBy,
  merge,
  ) where

-- Data.List.permutations

------------------------------------------------------------------------
-- Generators

-- subsets
-- sort . subset = sort . Data.List.subsequences
-- > subsets "abc" = ["","c","b","bc","a","ac","ab","abc"]
subsets :: [a] -> [[a]]
subsets []    = [[]]
subsets (h:t) = let s = subsets t in s ++ map (h:) s

-- combinations
-- > combinations "abc" 2 = ["ab","ac","bc"]
combinations :: Integral a => a -> [b] -> [[b]]
combinations 0 _      = [[]]
combinations _ []     = []
combinations n (h:t)  = (++ combinations n t) $ map (h:) $ combinations (n-1) t

-- slices
-- slices [1 .. 10] = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10]]
slices :: Int -> [a] -> [[a]]
slices n = takeWhile (not . null) . map (take n) . iterate (drop n)

-- substrings
-- > substrings 3 "watashi" = ["wat", "ata", "tas", "ash", "shi"]
substrings :: Int -> [a] -> [[a]]
substrings n a = take (length a - n + 1) $ map (take n) $ iterate tail a

-- pairs
-- pairs = map (\[i, j] -> (i, j)) . substrings 2
-- > pairs "pairs" = [('p','a'),('a','i'),('i','r'),('r','s')]
pairs :: [a] -> [(a, a)]
pairs []      = []
pairs a@(h:t) = zip a t

------------------------------------------------------------------------
-- Algorithms

-- binarySearchBy
binarySearchBy :: Integral a => (a -> Bool) -> a -> a -> a
binarySearchBy f s t = go s (t+1)
  where
    go l r
      | l == r    = r
      | f m       = go l m
      | otherwise = go (m+1) r
      where
        m = div (l + r) 2

-- merge
merge :: Ord a => [a] -> [a] -> [a]
merge = mergeBy compare

mergeBy :: Ord a => (a -> a -> Ordering) -> [a] -> [a] -> [a]
mergeBy cmp = merge'
  where
    merge' [] a = a
    merge' a [] = a
    merge' a@(i:x) b@(j:y)
      | cmp i j == GT = j:merge' a y
      | otherwise     = i:merge' x b

