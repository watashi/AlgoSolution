{-# LANGUAGE OverloadedLists #-}
{-# LANGUAGE OverloadedStrings #-}
{-# LANGUAGE PatternSynonyms #-}
import Control.Monad
import Control.Monad.Trans.State.Strict
import Data.Array (Array)
import Data.Array.IArray
import Data.Array.Unboxed (UArray)
import qualified Data.ByteString as ByteString
import Data.Bits
import Data.Word
import Data.List
import qualified Data.Map.Strict as Map
import Data.Ord
import Data.Sequence (Seq(..))
import Debug.Trace
import System.IO
import Text.Printf

minrepr :: UArray Word8 Word8
minrepr = listArray (minBound, maxBound)
  [ minimum [i `rotateR` r | r <- [0..7]]
  | i <- [0..]
  ]

masks :: [Word8]
masks = filter (\i -> i == minrepr!i) [1..]

newtype ByteSet = ByteSet ByteString.ByteString
  deriving (Eq, Ord)

instance Show ByteSet where
  show (ByteSet bs) = show $ ByteString.unpack bs

emptyset :: ByteSet
emptyset = ByteSet ""

mkset :: [Word8] -> ByteSet
mkset = ByteSet . ByteString.pack . map head . group . sort . map (minrepr!)

subsets :: ByteSet -> [ByteSet]
subsets (ByteSet bs) = case ByteString.uncons bs of
  Just (x, xs) ->
    let ys = subsets $ ByteSet xs
    in ys <> [ByteSet $ ByteString.cons x y | ByteSet y <- ys]
  Nothing -> [emptyset]

generate :: ByteSet -> Word8 -> Array Int ByteSet
generate (ByteSet bs) mask = fmap mkset $ accumArray (flip (:)) [] (0, 8)
  [ (popCount j, j)
  | i <- ByteString.unpack bs
  , r <- [0..7]
  , let j = (i `rotateR` r) `xor` mask
  ]

groups :: Array Int ByteSet
groups = generate (mkset masks) 0

nodes :: [ByteSet]
nodes = sort
  [ j
  | i <- elems groups
  , j <- subsets i
  , j /= emptyset
  ]

edges :: [(ByteSet, Word8, ByteSet)]
edges =
  [ (i, j, k)
  | i <- nodes
  , j <- masks
  , k <- elems $ generate i j
  , k /= emptyset
  ]

data S = S
  { todo :: Seq (Int, ByteSet)
  , done :: Map.Map ByteSet (Word8, Int)
  , degrees :: Map.Map (ByteSet, Word8) Int
  }

solution :: Map.Map ByteSet (Word8, Int)
solution = done $ go `execState` s0
  where
  graph = Map.fromListWith (++) [(k, [(i, j)]) | (i, j, k) <- edges]
  s0 = S
    { todo = [(0, mkset [0])]
    , done = Map.singleton (mkset [0]) (0, 0)
    , degrees = Map.fromListWith (+) [((i, j), 1) | (i, j, _) <- edges]
    }
  go = do
    todo0 <- gets todo
    case todo0 of
      Empty -> return ()
      (d, bs) :<| todo1 -> do
        modify' $ \s -> s{ todo = todo1 }
        forM_ (Map.findWithDefault [] bs graph) $ \k@(i, j) -> do
          x <- gets $ Map.findWithDefault 0 k . degrees
          modify' $ \s -> s { degrees = Map.insertWith (+) k (-1) $ degrees s }
          when (x == 1) $ do
            y <- gets $ Map.notMember i . done
            when y $ do
              modify' $ \s -> s
                { todo = todo s :|> (d + 1, i)
                , done = Map.insert i (j, d + 1) $ done s
                }
        go

main :: IO ()
main = do
  forM_ (elems groups) $ \i ->
    hPrintf stderr "%s: %s\n" (show i) $ show $ Map.lookup i solution
  hSetBuffering stdout LineBuffering
  re <- readLn
  replicateM_ re $ do
    printf "%08b\n" (0 :: Word8)
    go groups
  where
  go todo = do
    n <- readLn
    when (n > 0) $ do
      let
        done = todo!n
        mask = fst $ solution Map.! done
      printf "%08b\n" mask
      go $ generate done mask
