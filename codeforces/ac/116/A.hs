import Control.Monad

main = do
    n <- fmap read getLine
    a <- replicateM n $ fmap (foldl1 subtract . map read . words) getLine
    print $ maximum $ scanl1 (+) a

-- # 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
-- 735676 	Oct 3, 2011 3:09:27 PM 	watashi 	116A - Tram 	Haskell 	Accepted 	50 ms 	2000 KB 
