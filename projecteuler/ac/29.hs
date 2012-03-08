import Data.Set

main = putStrLn $ show $ size $ fromList $ [a ^ b | a <- [2 .. 100], b <- [2 .. 100]]

