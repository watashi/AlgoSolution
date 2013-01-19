import Data.Char
import Data.Maybe

main :: IO ()
main = do
  _ <- getLine
  w <- fmap (words) getLine
  putStrLn $ unwords $ filter (not . null) $ map (mapMaybe ((`lookup` tab) . toLower)) w
  where
    lst = ["zr", "bc", "dw", "tj", "fq", "lv", "sx", "pm", "hk", "ng"]
    tab = concat $ zipWith zip lst $ map repeat ['0' ..]
