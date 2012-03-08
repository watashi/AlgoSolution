import Data.Graph.Inductive.Graph (mkGraph)
import Data.Graph.Inductive.PatriciaTree (Gr)
import Data.Graph.Inductive.Query.SP (spLength)
import IO

main = do
	handle <- openFile "82matrix.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ spLength (-1) (-2) $ buildGraph input
	where
		buildGraph :: String -> Gr Int Int
		buildGraph input = mkGraph v e
			where
				a = map (\l -> read $ "[" ++ l ++ "]") $ lines input
				r = length $ a
				c = length $ a !! 0
				v = map (\x -> (x, x)) $ [-1, -2] ++ [0 .. r * c - 1]
				e = [(i * c + j, pred i * c + j, a !! i !! j) | i <- [1 .. r - 1], j <- [0 .. c - 1]] ++
					[(i * c + j, succ i * c + j, a !! i !! j) | i <- [0 .. r - 2], j <- [0 .. c - 1]] ++
					[(if j == -1 then -1 else i * c + j,
					if j == c - 1 then -2 else i * c + succ j,
					if j == -1 then 0 else a !! i !! j) | i <- [0 .. r - 1], j <- [-1 .. c - 1]]
		


