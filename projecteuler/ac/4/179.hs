import Data.List
import Primes

primeList = primesToN 10000

primeDivision n = f n primeList
  where
    f n q
      | n == 1       = []
      | mod n p /= 0 = [(n, 1)]
      | otherwise    = (p, length s - 1): f (fst $ last s) t
      where
        (p: t) = dropWhile (\i -> i * i <= n && mod n i /= 0) q
        s = takeWhile ((==0) . snd) $ iterate ((`divMod` p) . fst) (n, 0)

divisorNumber = product . map (succ . snd) . primeDivision

main = print $ sum $ map (pred . length) $ group $ map divisorNumber [2 .. 10^7]

-- ./179  25.15s user 0.13s system 98% cpu 25.774 total
