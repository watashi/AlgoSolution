import qualified Data.Set as S

test :: Int -> Bool
test m = go S.empty $ iterate f (1, 1, 1)
  where
    f (i, j, k) = (j, k, (i + j + k) `rem` m)
    go _ [] = undefined
    go s (h@(_, _, k): t)
      | k == 0        = False
      | S.member h s  = True
      | otherwise     = go (S.insert h s) t

main :: IO ()
main = print $ zip [(1::Int)..] $ filter test [3, 5 ..]
