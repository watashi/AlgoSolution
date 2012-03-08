import Data.Graph.Inductive.Graph
import Data.Graph.Inductive.PatriciaTree
import Data.Graph.Inductive.Query.MST
import IO

totalLength = (`div` 2) . sum . map (\(_, _, l) -> l) . labEdges

mstLength = sum . map (\(LP ((_, l): _)) -> l) . msTree

main = do
	handle <- openFile "107network.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ show $ (\g -> totalLength g - mstLength g) $ buildGraph input where
		buildGraph :: String -> Gr () Int
		buildGraph input = mkGraph v e where
			a = map (\l -> read $ "[" ++ l ++ "]") $ lines input
			n = length $ a
			v = [(i, ()) | i <- [0 .. n - 1]]
			e = [(i, j, k) | i <- [0 .. n - 1], j <- [0 .. n - 1], i /= j, k <- [a !! i !! j], k /= -1]
