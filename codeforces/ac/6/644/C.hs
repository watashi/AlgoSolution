import Control.Monad
import Data.Char
import Data.List
import qualified Data.Set as Set
import qualified Data.Map as Map
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  Just (n, _) <- fmap C.readInt C.getLine
  s <- replicateM n $ fmap (C.takeWhile (not . isSpace)) $ C.getLine
  let m = Map.fromListWith Set.union
        [ (domain, Set.singleton path)
        | i <- s
        , let (domain, path) = C.break (=='/') $ C.drop (C.length http) i
        ]
      mm = Map.fromListWith Set.union
        [ ((hash, pathSet), Set.singleton domain)
        | (domain, pathSet) <- Map.toList m
        , let hash = foldl1' (\i j -> i * 97 + j)
                [ B.foldl' (\h b -> h * 29 + fromIntegral b) (7 :: Int) i
                | i <- Set.toList pathSet
                ]
        ]
      ans = [ C.unwords $ map (C.append http) i
            | i <- map Set.toList $ Map.elems mm
            , not $ null $ drop 1 i
            ]
  print $ length ans
  C.putStrLn $ C.unlines ans
  where
  http = C.pack "http://"
