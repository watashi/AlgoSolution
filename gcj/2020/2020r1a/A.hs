import Control.Monad
import qualified Data.ByteString.Char8 as C
import Data.List
import Data.Ord
import Text.Printf

gao :: [C.ByteString] -> Maybe C.ByteString
gao xs
  | all (`C.isPrefixOf` x) xs = Just x
  | otherwise = Nothing
  where
  x = maximumBy (comparing C.length) xs

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [(1 :: Int) .. re] $ \ri -> do
    n <- readInt <$> C.getLine
    patterns <- replicateM n $ do
      prefix: rest <- C.split '*' <$> C.getLine
      let other = filter (not . C.null) $ init rest
          suffix = last rest
      return ((prefix, suffix), other)
    let (ends, others) = unzip patterns
        (prefixes, suffixes) = unzip ends
    printf "Case #%d: %s\n" ri $
      case (gao prefixes, fmap C.reverse $ gao $ map C.reverse suffixes) of
        (Just prefix, Just suffix) -> C.unpack $ C.concat $
          prefix: concat others ++ [suffix]
        _ -> "*"
  where
  readInt s = let Just (i, _) = C.readInt s in i
