import Data.List
main = interact ((["IGNORE HIM!", "CHAT WITH HER!"]!!) . (`mod` 2) . length . nub)
