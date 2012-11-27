import Data.Maybe
import qualified Data.ByteString.Char8 as C

main = do
  let readInt =  fst . fromJust . C.readInt
  (n:m:input) <- fmap (map (readInt) . C.words) C.getContents
  let (u:v:a, input') = splitAt (n+2) $ map fromIntegral input
      (b, c) = splitAt m input'
      (ans, x, y) = minimum $ gao u v (zip [1 ..] a) (zip3 [1 ..] b c)
  putStrLn $ show x ++ " " ++ show y

hypot x y = sqrt $ x * x + y * y

gao u v a b = go a b
  where
    go _ [] = []
    go a ((j, r, d): t) = (dist l, i, j): go a' t
      where
        dist l = hypot u l + hypot (v - u) (r - l) + d
        a'@((i, l): _) = best a
        best [h] = [h]
        best l1@((_, h1): l2@((_, h2): t)) =
          if dist h2 <= dist h1 then best l2 else l1

