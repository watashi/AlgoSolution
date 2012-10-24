import System.IO
import Data.List
import Data.Maybe

parseCard (r:s:dummy) = (idx "23456789TJQKA" r, idx "SHDC" s)
  where
    idx a e = fromJust $ elemIndex e a

score cards = score:combs
  where
    score
      | straight && flush   = 9
      | find 4              = 8
      | find 3 && find 2    = 7
      | flush               = 6
      | straight            = 5
      | find 3              = 4
      | length (comb 2) > 1 = 3
      | find 2              = 2
      | otherwise           = 1

    hand = reverse $ sort $ map parseCard $ cards
    (rank, suit) = unzip hand

    comb n = map head $ filter ((==n) . length) $ group $ rank
    find n = not $ null $ comb n
    combs = concat [comb i | i <- [4, 3, 2, 1]]

    straight = all (==1) $ zipWith (-) rank $ tail rank
    flush = (==1) $ length $ group $ suit

win hands = score lhs > score rhs
  where (lhs, rhs) = splitAt 5 hands

main = do
  handle <- openFile "54poker.txt" ReadMode
  input <- hGetContents handle
  print $ length $ filter id $ map (win . words) $ lines input
