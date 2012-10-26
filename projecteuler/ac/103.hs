import qualified Data.IntSet as S
import Data.List

gao n m = map adjust $ gen (pred n) 1 $ replicate (div n 2) $ S.singleton 0
  where
    gen 0 _ s@(h:_) = [h]
    gen k r s@(h:t) = concat [gen (pred k) (succ i) $ S.insert i h: zipWith S.union t t' |
      i <- [r .. m],
      t' <- [map (S.map (+i)) $ init s],
      all S.null $ zipWith S.intersection t t']
    adjust a = S.map (+d) a
      where
        b = S.toList a
        d = max 0 $ maximum $ zipWith (-) (scanl (+) 1 $ reverse b) $ scanl1 (+) b

main = do
  print $ sort $ map (\i -> (sum $ S.toList i, i)) $ gao 7 25
