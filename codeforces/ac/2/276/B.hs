import Data.List

main :: IO ()
main = do
  s <- getLine
  let t = length $ filter odd $ map length $ group $ sort s
  putStrLn $ if t == 0 || odd t then "First" else "Second"
