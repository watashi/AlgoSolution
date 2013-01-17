import Data.Array
import Data.List
import Data.Maybe
import Data.Tuple
import qualified Data.ByteString.Char8 as C

pairs :: [a] -> [(a, a)]
pairs (x:y:z) = (x, y): pairs z
pairs _ = []

comm :: [Int] -> [Int] -> Int
comm [] _ = 0
comm _ [] = 0
comm a@(ah:at) b@(bh:bt) =
  case compare ah bh of
    LT -> comm at b
    EQ -> succ $ comm at bt
    GT -> comm a bt

ok :: [Int] -> [Int] -> Bool
ok a b = (==2) $ comm a b

fromList :: Int -> [(Int, Int)] -> Array Int [Int]
fromList n el = fmap sort $ accumArray (flip (:)) [] (1, n) $ el ++ map swap el

main :: IO ()
main = do
  (n:el) <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
  let e = fromList n $ pairs el
      gao v p ret = if w == 1 || w == -1 then ret else gao w v (w:ret)
        where
          w = head $ (++[-1]) $ filter (\i -> i /= p && ok (e!v) (e!i)) $ e!v
      ans
        | fmap length e /= listArray (1, n) (repeat 4) = []
        | n <= 8    = head $ (++[[]]) $ filter check $ permutations [1 .. n]
        | otherwise = gao 1 1 [1]
        where
          check p = (==e) $ fromList n $ zip p (rot 1 p) ++ zip p (rot 2 p)
          rot k a = let (l, r) = splitAt k a in r ++ l
  if length ans == n
    then putStrLn $ unwords $ map show $ ans
    else putStrLn "-1"
