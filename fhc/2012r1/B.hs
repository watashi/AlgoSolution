import Control.Arrow
import Control.Monad
import Data.List

newtype State s a = State {
  runState :: s -> (a, s)
}

instance Monad (State s) where
  return a = State $ \s -> (a, s)
  m >>= f  = State $ \s -> let (a', s') = runState m s in runState (f a') s'

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    n <- fmap read getLine
    s <- fmap (map (=='1')) getLine
    let (a, _) = runState (unmerge n) s
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show (checksum a)
  where
    checksum = foldl' (\i j -> mod (i * 31 + j) 1000003) (1::Int)
    shift = State $ \(h:t) -> (h, t)

    unmerge n
      | n <= 1    = return [1 .. n]
      | otherwise = do
        l <- unmerge $ m
        r <- unmerge $ n - m
        (l', r') <- unmerge' [1 .. n] m $ n - m
        return $ remap l l' ++ remap r r'
      where
        m = n `div` 2
        remap x y = map snd $ sort $ (`zip` y) $ map snd $ sort $ zip x [1::Int ..]

    unmerge' a 0 _ = return ([], a)
    unmerge' a _ 0 = return (a, [])
    unmerge' (h:t) l r = do
      lt <- shift
      if lt
        then liftM (first (h:)) $ unmerge' t (l - 1) r
        else liftM (second (h:)) $ unmerge' t l (r - 1)
    unmerge' _ _ _ = undefined
