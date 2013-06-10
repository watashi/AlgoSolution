import Data.Array
import Data.Ratio
import qualified Data.Set as S

gao :: Int -> [Ratio Int]
gao n = a!n
  where
    -- uniq = map head . group . sort
    uniq = S.toList . S.fromList
    a = listArray (1, n) $ map go [1 .. n]
    go 1 = [1]
    go i = uniq $ concat $ a!(i-1): [[w, (u * v) / w] |
      j <- [1 .. i `quot` 2],
      u <- a!j,
      v <- a!(i-j),
      let w = u + v]

main :: IO ()
main = mapM_ (print . length . gao) [1 .. 18]
