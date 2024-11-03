import Control.DeepSeq
import Control.Monad
import Data.Array
import Data.ByteString (ByteString)
import qualified Data.ByteString.Char8 as C
import Data.Graph

readInt :: ByteString -> Int
readInt = maybe (error "readInt") fst . C.readInt

readInts :: ByteString -> [Int]
readInts = map readInt . C.words

gao :: Array Int Int -> Graph -> Int -> Int
gao a g c = uncurry max $ dfs 1 1
  where
    dfs v p = force $
      ( (a!v) + sum [max (i - 2 * c) j | (i, j) <- ws]
      , sum [max i j | (i, j) <- ws]
      )
      where
        ws = [dfs w v | w <- g!v, w /= p]

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \_ri -> do
    n: c: _ <- readInts <$> C.getLine
    a <- readInts <$> C.getLine
    e <- fmap concat $ replicateM (n - 1) $ do
      i: j: _ <- readInts <$> C.getLine
      return $ [(i, j), (j, i)]
    print $ gao (listArray (1, n) a) (buildG (1, n) e) c

-- 286803447	Oct/19/2024 08:45UTC-7	watashi	2014F - Sheriff's Defense	Haskell	Accepted	812 ms	158800 KB
-- 286802005	Oct/19/2024 08:42UTC-7	watashi	2014F - Sheriff's Defense	Haskell	Accepted	827 ms	146400 KB
