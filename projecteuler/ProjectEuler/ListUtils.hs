{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
-- | Operations on lists that are not provided Data.List.
module ProjectEuler.ListUtils (
  -- * Array operations
  -- | These functions treat a list @xs@ as a indexed array,
  -- with indices ranging from 0 to 'length' @xs@ - 1.
  replace,
  replaceWith,
  replaceWithIndex,

  -- * Set operations
  -- | These functions treat a /sorted/ list as a set.
  setDifference,
  setIntersection,
  setSymmetricDifference,
  setUnion,

  -- ** Generalized set operations
  setDifferenceBy,
  setIntersectionBy,
  setSymmetricDifferenceBy,
  setUnionBy,
  ) where

import Control.Arrow (second)
import Data.List (sortBy)
import Data.Function (on)

-- ---------------------------------------------------------------------------
-- Array operations

-- | The 'replace' function constructs a list identical to the first argument
-- except that it has been updated by the associations in the second argument.
-- If there are repeated indices, the last value will be used.
-- For example,
--
-- > [2, 3, 4, 5] `replace` [(2, 5), (3, 6), (3, 7)] = [2, 3, 5, 7]
replace :: [a] -> [(Int, a)] -> [a]
replace a b = replaceWithIndex a $ map (second $ const . const) b

-- | The 'replaceWith' function is a generalized version of 'replace', which
-- maps the associated function over given indices. If there are repeated
-- indices are, functions will be applied ono by one in the order they are
-- given as if they are composited. For example,
--
-- > [2, 3, 4, 5] `replaceWith` [(2, succ), (3, (*3)), (3, (`quot`2))] = [2, 3, 5, 7]
replaceWith :: [a] -> [(Int, (a -> a))] -> [a]
replaceWith a b = replaceWithIndex a $ map (second const) b

-- | The 'replaceWithIndex' function is a generalized version of 'replaceWith',
-- where the associated function takes the index and the original value and
-- returns the new value. For example,
--
-- > [2, 3, 4, 5] `replaceWithIndex` [(2, const succ), (3, (+)), (3, const pred)] = [2, 3, 5, 7]
replaceWithIndex :: [a] -> [(Int, (Int -> a -> a))] -> [a]
replaceWithIndex a b = go 0 a b'
  where
    b' = dropWhile ((<0) . fst) $ sortBy (compare `on` fst) $ b
    go _ [] _ = []
    go _ x [] = x
    go i (e:xt) y@((j,f):yt)
      | i < j     = e: go (succ i) xt y
      | otherwise = go i (f i e: xt) yt

-- ---------------------------------------------------------------------------
-- Set operations

setDifference, setIntersection, setSymmetricDifference, setUnion ::
  Ord a => [a] -> [a] -> [a]

-- | The 'setDifference' function returns the difference of
-- two sorted lists. For example,
--
-- > [1, 2, 2, 3, 3, 3] `setDifference` [2, 3, 3] = [1, 2, 3]
setDifference          = setDifferenceBy          compare

-- | The 'setIntersection' function returns the intersection of
-- two sorted lists. For example,
--
-- > [1, 2, 3, 4] `setIntersection` [2, 2, 3] = [2, 3]
setIntersection        = setIntersectionBy        compare

-- | The 'setSymmetricDifference' function returns the symmetric difference of
-- two sorted lists. For example,
--
-- > [1, 2] `setSymmetricDifference` [2, 2, 3] = [1, 2, 3]
setSymmetricDifference = setSymmetricDifferenceBy compare

-- | The 'setUnion' function returns the union of
-- two sorted lists. For example,
--
-- > [1, 2, 2] `setUnion` [1, 1, 2] = [1, 1, 2, 2]
setUnion               = setUnionBy               compare

setDifferenceBy, setIntersectionBy, setSymmetricDifferenceBy, setUnionBy ::
  Ord a => (a -> a -> Ordering) -> [a] -> [a] -> [a]

-- | The 'setDifferenceBy' function is the non-overloaded version of
-- 'setDifference'.
setDifferenceBy cmp = go
  where
    go a [] = a
    go [] _ = []
    go a@(i:x) b@(j:y) =
      case cmp i j of
        LT -> i: go x b
        EQ -> go x y
        GT -> go a y

-- | The 'setIntersectionBy' function is the non-overloaded version of
-- 'setIntersection'.
setIntersectionBy cmp = go
  where
    go _ [] = []
    go [] _ = []
    go a@(i:x) b@(j:y) =
      case cmp i j of
        LT -> go x b
        EQ -> i: go x y
        GT -> go a y

-- | The 'setSymmetricDifferenceBy' function is the non-overloaded version of
-- 'setSymmetricDifference'.
setSymmetricDifferenceBy cmp = go
  where
    go a [] = a
    go [] b = b
    go a@(i:x) b@(j:y) =
      case cmp i j of
        LT -> i: go x b
        EQ -> go x y
        GT -> j: go a y

-- | The 'setUnionBy' function is the non-overloaded version of
-- 'setUnion'.
setUnionBy cmp = go
  where
    go a [] = a
    go [] b = b
    go a@(i:x) b@(j:y) =
      case cmp i j of
        LT -> i: go x b
        EQ -> i: go x y
        GT -> j: go a y

