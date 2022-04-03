{-# LANGUAGE RecordWildCards #-}

import Control.Monad
import Control.Monad.IO.Class
import Control.Monad.State.Lazy
import qualified Data.IntMap.Strict as Map
import Data.Maybe
import qualified Data.Sequence as Seq
import System.IO
import System.Random

getResp :: IO (Int, Int)
getResp = do
  (r:p:_) <- fmap read . words <$> getLine
  return (r, p)

shuffle :: RandomGen g => g -> [Int] -> [Int]
shuffle g list = go (Seq.fromList list) `evalState` g
  where
  go s
    | Seq.null s = return []
    | otherwise = do
      i <- state $ randomR (0, Seq.length s - 1)
      case Seq.splitAt i s of
        (l, m Seq.:<| r) -> (m:) <$> go (l <> r)
        _ -> return []

data S = S
  { todo :: [Int]
  , fromt :: Map.IntMap Int
  , fromw :: Map.IntMap Int
  } deriving Show

solve :: Int -> Bool -> StateT S IO ()
solve k w
  | k == 0 = return ()
  | w = do
    liftIO $ putStrLn "W"
    (r, p) <- liftIO getResp
    modify' $ \s -> s
      { fromw = Map.insert r p $ fromw s
      }
    solve (k - 1) False
  | otherwise = do
    m <- gets $ listToMaybe . todo
    modify' $ \s -> s{ todo = tail $ todo s }
    case m of
      Nothing -> return ()
      Just r -> do
        visited <- gets $ Map.lookup r . fromw
        (used, p) <- case visited of
          Just p -> return (0, p)
          Nothing -> do
            liftIO $ putStrLn $ "T " <> show r
            (_, p) <- liftIO getResp
            return (1, p)
        modify' $ \s -> s
          { fromt = Map.insert r p $ fromt s
          }
        solve (k - used) (p == 1)

main :: IO ()
main = do
  hSetBuffering stdout LineBuffering
  re <- readLn
  replicateM_ re $ do
    (n, k) <- getResp
    (r, p) <- getResp
    g <- newStdGen
    let
      s0 = S
        { todo = shuffle g $ filter (/=r) [1..n]
        , fromt = Map.singleton r p
        , fromw = Map.empty
        }
    S{..} <- solve k (p == 1) `execStateT` s0
    let
      ceil a b = (a + b - 1) `quot` b
      fromtOnly = fromt `Map.difference` fromw
      ans = ceil (sum fromw + ceil (sum fromtOnly * (n - length fromw)) (length fromtOnly)) 2
    putStrLn $ "E " <> show ans
