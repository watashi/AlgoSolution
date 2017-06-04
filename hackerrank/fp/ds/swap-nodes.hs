import Control.Applicative
import Control.Monad
import Data.Array

data Tree a
  = Bin a (Tree a) (Tree a)
  | Nil
  
inorder :: Tree a -> [a]
inorder = go []
  where
  go acc Nil = acc
  go acc (Bin v l r) = go (v: go acc r) l
  
swap :: Int -> Tree a -> Tree a
swap k = go k
  where
  go _ Nil = Nil
  go 1 (Bin v l r) = Bin v (go k r) (go k l)
  go i (Bin v l r) = Bin v (go (i-1) l) (go (i-1) r)

main :: IO ()
main = do
  n <- readLn
  a <- fmap (listArray (1, n)) $ replicateM n $ do
    (i:j:_) <- map read . words <$> getLine
    return (i, j)
  let buildT (-1) = Nil
      buildT v = let (l, r) = a!v in Bin v (buildT l) (buildT r)
      tree = buildT 1
  m <- readLn
  q <- replicateM m readLn
  (\f -> foldM_ f tree q) $ \t k -> do
    let t' = swap k t
    putStrLn $ unwords $ map show $ inorder t'
    return t'