import Control.Monad
import Data.Array
import Data.Bits
import Data.List
import Data.Maybe
import qualified Data.IntMap as M
import qualified Data.ByteString.Char8 as C

toGraph n = accumArray (flip (:)) [] (1, n)

color n e = array (1, n) $ M.assocs $ foldl (dfs True) M.empty [1 .. n]
  where
    dfs t c v
      | M.member v c = c
      | True = foldl (dfs (not t)) (M.insert v t c) $ e!v

try12 n e r b
  | null u = Nothing
  | True = Just $ (u':v') ++ (delete u' r) ++ (b \\ v')
  where
    m = length b
    u = [i | i <- r, length (e!i) <= m - 2]
    u' = head u
    v = [j | j <- b, notElem u' $ e!j]
    v' = take 2 v

try42 n e r b
  | length v' < 6 = Nothing
  | True = Just $ v' ++ (r \\ v') ++ (b \\ v')
  where
    m = length b
    x = foldr1 xor b
    e' = toGraph n [(foldr xor x $ e!i, i) | i <- r, length (e!i) == m - 1]
    v' = concat $ take 2 [i: take 2 j | (i, j) <- assocs e', length j >= 2]

yes v = putStrLn $ ("YES\n" ++) $ unwords $ map show $ elems w
  where
    n = length v
    w = array (1,n) $ zip v $ concatMap (replicate 3) [1 ..]

solve n e =
  if m == 0
  then
    yes $ r ++ b
  else
    case try12 n e x y of
      Just z -> yes z
      _      ->
        case try42 n e x y of
          Just z -> yes z
          _      -> putStrLn "NO"
  where
    c = color n e
    r = [i | (i, e) <- assocs c, e]
    b = [i | (i, e) <- assocs c, not e]
    m = length r `mod` 3
    (x, y) = if m /= 2 then (r, b) else (b, r)

get = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine

main = do
  [n, m] <- get
  e <- replicateM m get
  solve n $ toGraph n $ concat [[(i, j), (j, i)] | [i, j] <- e]

