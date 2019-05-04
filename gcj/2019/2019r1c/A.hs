import Control.Monad
import Data.Maybe
import Text.Printf

gao :: [String] -> Maybe String
gao s = case (ps, rs, ss) of
  (_p, [], []) -> Just "S"
  ([], _r, []) -> Just "P"
  ([], [], _s) -> Just "R"
  ([], _r, _s) -> ('R':) <$> gao rs
  (_p, [], _s) -> ('S':) <$> gao ss
  (_p, _r, []) -> ('P':) <$> gao ps
  _ -> Nothing
  where
  ps = [i | ('P':i) <- s]
  rs = [i | ('R':i) <- s]
  ss = [i | ('S':i) <- s]

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    n <- readLn
    inputs <- replicateM n $ filter (`elem` "PRS") <$> getLine
    let ans = gao $ map cycle inputs
    printf "Case #%d: %s\n" ri $ fromMaybe "IMPOSSIBLE" ans
