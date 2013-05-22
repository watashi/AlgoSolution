{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
-- | Operations on lists that are not provided Data.List.
module ProjectEuler.ListUtils (
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

