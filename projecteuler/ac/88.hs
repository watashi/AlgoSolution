import Data.Array
import Data.List

limit = 12000

prodsum = ps 0 (2, 1, 0) where
	ps l (a, p, s) = ((p - s + l, p) :) $ concat $ map (ps (succ l)) $ takeWhile (\(_, b, c) -> b - c + l < limit) $ [(i, p * i, s + i) | i <- [a .. limit + limit]]

main = do print $ sum $ map head $ group $ sort $ tail $ elems $ accumArray min 2000000000 (1, limit) $ prodsum

