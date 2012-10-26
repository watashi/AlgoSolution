import Enumeration
import Primes

size = 10

join = foldr1 (\i j -> j * 10 + i)
split 0 = []
split n = let (d, m) = divMod n 10 in m: split d

solve d = head $ filter (not . null) $ [solve' i | i <- [0 .. size]]
  where
    solve' n = [k |
      diff <- [filter (notElem d) $ map split [0 .. 10^n-1]],
      i <- combinations n [0 .. size-1],
      base <- [join [if elem r i then 0 else d | r <- [0 .. size-1]]],
      j <- diff,
      k <- [(base +) $ sum $ zipWith (\r t -> t * 10^r) i j],
      k >= 10 ^ (size-1),
      isPrime k]

main = do
  print $ sum [sum $ solve i | i <- [0 .. 9]]

-- ./111  1.21s user 0.01s system 60% cpu 2.013 total
