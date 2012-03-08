import Numeric
import Data.Map

gao [] c = [(c, 1)]
gao (a:as) c = toList $ fromListWith (+) $ concat [gao as (c + d) | d <- [1 .. a]]

main = putStrLn $ showFFloat (Just 7) (fromIntegral num / fromIntegral den) ""
	where
		peter = gao (take 9 $ repeat 4) 0
		colin = gao (take 6 $ repeat 6) 0
		num = sum [snd p * snd c | p <- peter, c <- colin, fst p > fst c]
		den = sum [snd p * snd c | p <- peter, c <- colin]

