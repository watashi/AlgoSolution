import Data.Bits
import Data.Char
import System.IO

decrypt text pass = zipWith xor text $ concat $ repeat pass

check text =
  all isPrint text &&
  all id [r * length (filter (==c) text) >= length text |
    (c, r) <- zip " etaoinsh" [10, 15 ..]]

main = do
  handle <- openFile "59cipher1.txt" ReadMode
  input <- hGetContents handle
  putStrLn $ unlines $ map dump $ filter check $ [map chr $ decrypt t p |
    t <- [read $ "[" ++ input ++ "]"], p <- pass]
  where
    pass = sequence $ take 3 $ repeat $ map ord $ ['a' .. 'z']
    dump s = show $ (s, sum $ map ord s)
