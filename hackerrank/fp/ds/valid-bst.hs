import Control.Applicative

data Tree a
  = Bin a (Tree a) (Tree a)
  | Nil

buildBST :: Ord a => [a] -> Maybe (Tree a)
buildBST [] = Just Nil
buildBST (h: t)
  | all (>h) r = Bin h <$> buildBST l <*> buildBST r
  | otherwise = Nothing
  where
  (l, r) = span (<h) t

main :: IO ()
main = do
  re <- readLn
  sequence_ . replicate re $ do
    _ <- getLine
    a <- map read . words <$> getLine :: IO [Int]
    putStrLn $ maybe "NO" (const "YES") $ buildBST a