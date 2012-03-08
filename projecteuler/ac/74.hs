import Data.Array
import Data.Char
import Data.List

factorial n = factorials !! n
	where factorials = scanl1 (*) (1 : [1 .. 9])

size = 1000000

chains = listArray (1, size) [chain i | i <- [1 .. size]]
chain 1			= 1
chain 2			= 1
chain 145		= 1
chain 40585		= 1{--!!--}
chain 871		= 2
chain 45361		= 2
chain 872		= 2
chain 45362		= 2
chain 169		= 3
chain 363601	= 3
chain 1454		= 3
chain n			= 1 + if m <= size then chains ! m else chain m
	where m = sum [factorial $ digitToInt $ ch | ch <- show n]

main = putStrLn $ show $ length $ filter (==60) $ elems $ chains
