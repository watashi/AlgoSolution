import Data.List
import Control.Monad

main :: IO ()
main = do
  n <- fmap read getLine
  a <- replicateM n $ fmap readDate getLine
  let holiday = gao date weekend (sort a) (0::Int)
  print $ maximum $ (0:) $ map length $ filter or $ group holiday
  where
    readDate :: String -> (Int, Int)
    readDate s = let (m, d) = break (=='/') s in (read m, read $ tail d)
    dom = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    date = [(i, j) | (i, n) <- zip [1 ..] dom, j <- [1 .. n]]
    weekend = cycle [True, False, False, False, False, False, True]
    gao [] _ _ _ = []
    gao (a:as) (b:bs) c d =
      if b then True: gao as bs c' d'
      else if d' > 0 then True: gao as bs c' (d' - 1)
      else False: gao as bs c' d'
      where
        holiday = not (null c) && head c == a
        c' = if holiday then tail c else c
        d' = if holiday then d + 1 else d
