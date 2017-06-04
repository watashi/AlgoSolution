{-# LANGUAGE RecordWildCards #-}

import Control.Monad
import Data.Array

data KMP a = KMP
  { pat :: Array Int a
  , pfail :: Array Int Int
  } deriving (Show)

newKMP :: Eq a => [a] -> KMP a
newKMP a = KMP{..}
  where
  n = length a
  pat = listArray (0, n-1) a
  pfail = listArray (0, n-1) $ (-1):
    [ if pat!(k+1) == e then k+1 else -1
    | (i, e) <- tail $ assocs pat
    , let k = until (\j -> j < 0 || pat!(j+1) == e) (pfail!) (pfail!(i-1))
    ]

runKMP :: Eq a => KMP a -> [a] -> [Int]
runKMP KMP{..} = go 0
  where
  go _ [] = []
  go k b@(h:t)
    | k <= snd (bounds pat) && h == pat!k = let k' = k + 1 in k': go k' t
    | k > 0 = let k' = pfail!(k-1) + 1 in go k' b
    | otherwise = 0: go 0 t
    
main :: IO ()
main = do
  (_:inputs) <- fmap lines getContents
  forM_ (takeWhile (not . null) $ iterate (drop 2) inputs) $ \(t:p:_) -> do
    let kmp = newKMP p
        idx = runKMP kmp t
        ans = any (> snd (bounds $ pat kmp)) idx
    putStrLn $ if ans then "YES" else "NO"