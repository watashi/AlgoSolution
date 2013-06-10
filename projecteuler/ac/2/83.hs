import Control.Arrow ((***))
import Data.Graph.Inductive.Graph (mkGraph, noNodes)
import Data.Graph.Inductive.PatriciaTree (Gr)
import Data.Graph.Inductive.Query.SP (spLength)
import IO

main = do
	handle <- openFile "82matrix.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ (\g -> spLength 0 (noNodes g - 1) g) $ buildGraph input
	where
		buildGraph :: String -> Gr () Int
		buildGraph input = mkGraph v e
			where
				a = map (\l -> read $ "[" ++ l ++ "]") $ lines input
				r = length $ a
				c = length $ a !! 0
				v = map (\x -> (x, ())) $ [0 .. r * c]
				d = [pred *** id, succ *** id, id *** pred, id *** succ]
				e = (r * c - 1, r * c, a !! (r - 1) !! (c - 1)) :
					[(s, t, if j == -1 then 0 else a !! i !! j) |
					i <- [0 .. r - 1], j <- [0 .. c - 1],
					s <- [k (i, j)], o <- d, t <- [k $ o (i, j)], t /= -1]
				k (i, j) = if 0 <= i && i < r && 0 <= j && j < c then i * c + j else -1
		


