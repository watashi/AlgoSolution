import Data.Map.Strict (Map)
import qualified Data.Map.Strict as Map

data Dice = Dice
  { top   :: Int
  , front :: Int
  , left  :: Int
  } deriving (Eq, Ord, Show)

bottom, back, right :: Dice -> Int
bottom = (7-) . top
back = (7-) . front
right = (7-) . left

rotR, rotD :: Dice -> Dice
rotR d = Dice (left d) (front d) (bottom d)
rotD d = Dice (back d) (top d) (left d)

dice :: Dice
dice = Dice 1 2 3

dp :: [[Map Dice Int]]
dp = iterate gen dp0
  where
  rotAll rot m = Map.fromList
    [ (k', v + top k')
    | (k, v) <- Map.assocs m
    , let k' = rot k
    ]
  dp0 = iterate (rotAll rotR) $ Map.singleton dice $ top dice
  gen pre = ret
    where
    ret = zipWith (Map.unionWith max)
      (map (rotAll rotD) pre)
      (Map.empty: map (rotAll rotR) ret)

main :: IO ()
main = do
  re <- readLn
  sequence_ . replicate (dp!!60!!60 `seq` re) $ do
    (m:n:_) <- fmap (map read . words) getLine
    print $ maximum $ Map.elems $ dp!!(m-1)!!(n-1)