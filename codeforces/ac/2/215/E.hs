base b = map (`mod`b) . takeWhile (>0) . iterate (`div`b)

bitLength n = until ((>n) . (2^)) succ 0

period r n = max 0 $ u - div b 2 + 1
  where
    b = 2 ^ r
    d = base b n
    u = let (h:t) = reverse d in unit h t
    unit a []    = a
    unit a (h:t) =
      case compare h a of
        LT -> a - 1
        EQ -> unit a t
        GT -> a

periods n = d
  where
    w = bitLength n
    c = 0: map (`period` n) [1 .. w]
    d = 0: map f [1 .. w]
    f r
      | mod w r > 0 = 0
      | otherwise   = c!!r - sum [d!!i | i <- [1 .. r - 1], mod r i == 0]

count n = sum $ concatMap (init . periods) $ n: [2^i-1 | i <- [1 .. w - 1]]
  where
    w = bitLength n

main = do
  [l, r] <- fmap (map read . words) getLine
  print $ count r - count (l - 1)

