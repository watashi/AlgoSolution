import Data.Char (digitToInt)
import Data.List (find, group)
import Data.Maybe (isNothing)

factorial n = factorials !! n
	where factorials = scanl1 (*) (1 : [1 .. 9])

chain n = chain' n [n]
	where chain' x xs = if isNothing $ find (==x') xs then chain' x' (x:xs) else xs
		where x' = sum [factorial $ digitToInt $ ch | ch <- show x]

generate l d
	| l == 1	= [i | i <- [d .. 9]]
	| otherwise	= [i + j * 10 | i <- [d .. 9], j <- generate (l - 1) i]


main =
	putStrLn $ show $ filter ((==60) . length . chain) todo
	where
		todo = concat [generate l 0 | l <- [1 .. 6]]
--		calc = sum . map ((factorial 6 `div`) . permutaion)
--		permutaion n = product $ map (factorial . length) $ group $ take 6 $ reverse (show n) ++ repeat '0'
{-- [9740,9741,974322] --}

