import Control.Monad

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    s <- getLine
    let n = length s
        rotate (h: t) = t ++ [h]
        ans = take n $ iterate rotate $ rotate s
    putStrLn $ unwords ans