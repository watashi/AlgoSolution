import Control.Monad
import Data.Functor
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1..re] $ \ri -> do
    as <- replicateM 3 $ fmap readInt . C.words <$> C.getLine
    let
      b = foldl1 (zipWith min) as
    putStrLn $ "Case #" <> show ri <> ": " <> case go 1000000 b of
      Just ans -> unwords $ map show ans
      Nothing -> "IMPOSSIBLE"
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
    go r [] = guard (r == 0) $> []
    go r (x:xs) = let y = min r x in (y:) <$> go (r - y) xs
