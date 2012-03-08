-- orz | from: haskell.org
import Data.Array
import Data.List

collatzs s = a
	where a = listArray (1, s) $ 1 : [collatz i | i <- [2 ..]]
		where collatz n = y + a ! x
			where (x, y) = until ((<=s) . fst) (\(a, b) -> (next a, b + 1)) (next n, 1)
				where next n = if even n then div n 2 else 3 * n + 1

-- *** Exception: maximum
-- foldl -> foldl'
main = putStrLn $ show $ foldl1' (max) $ map (\(a, b) -> (b, a)) $ assocs $ collatzs 1000000

