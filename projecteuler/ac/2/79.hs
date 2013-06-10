import Data.Char
import Data.Graph
import Data.List
import IO

main = do
	handle <- openFile "79keylog.txt" ReadMode
	input <- hGetContents handle
	putStrLn $ map chr $ topSort $ buildG (ord '0', ord '9') $ map head $ group $ sort $ concat $ map (\x -> let y = map ord x in zip y $ tail y) $ lines input

{-- of course, topSort is not the right approch, but it works for this input.txt --}
