import Control.Applicative
import Control.Monad.Trans.State
import qualified Data.IntMap.Strict as Map
import Data.List
import Data.Maybe

gao :: [Int] -> Int -> Maybe [Int]
gao d = flip evalState Map.empty . f
  where
  f 1 = return $ Just []
  f n = do
    cache <- gets $ Map.lookup n
    case cache of
      Just ret -> return ret
      Nothing -> do
        a <- sequence [fmap (i:) <$> f j | i <- d, (j, 0) <- [n `quotRem` i]]
        let ret = case catMaybes a of
              [] -> Nothing
              b -> Just $ minimumBy cmp b
        modify $ Map.insert n ret
        return ret
  cmp a b = case length a `compare` length b of
    EQ -> head a `compare` head b
    ret -> ret

main :: IO ()
main = do
  let getInts = map read . words <$> getLine
  (n:_) <- getInts
  d <- getInts
  case gao d n of
    Just ans -> putStrLn $ unwords $ map show $ scanl (*) 1 ans
    Nothing -> print $ -1
