-- 1/n-1/x=(x-n)/(nx)=1/y
-- x-n | nx
-- i | n(n+i)
-- i | n^2 (1<=i<=n)

import Primes

primeList = primesToN 1000000

primeDivision n = f n primeList
  where
    f n q
      | n == 1       = []
      | mod n p /= 0 = [(n, 1)]
      | otherwise    = (p, length s - 1): f (fst $ last s) t
      where
        (p: t) = dropWhile (\i -> i * i <= n && mod n i /= 0) q
        s = takeWhile ((==0) . snd) $ iterate ((`divMod` p) . fst) (n, 0)

solutionNumber = (`div` 2) . succ . product . map (succ . (*2) . snd) . primeDivision

main = print $ take 10 $ [(n, solutionNumber n) | n <- [1260 ..], solutionNumber n > 1000]

-- ./108  0.45s user 0.00s system 30% cpu 1.467 total

