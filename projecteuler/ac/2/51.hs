import qualified Data.Map as M
import Primes (primesToN)

p = primesToN 1000000

mask x = let y = show x in filter (/=y) $ concat [mask' y i | i <- ['0' .. '9']] where
	mask' [] _ = [""]
	mask' (h:t) c = let a = mask' t c in [h : i | i <- a] ++ (if h == c then ['*' : i | i <- a] else [])

main = do putStrLn $ show $ M.filter ((>= 8) . fst) $ gao where
	gao = M.fromListWith (\(a, b) (c, d) -> (a + c, min b d)) [(k, (1, v)) | v <- p, k <- mask v]

