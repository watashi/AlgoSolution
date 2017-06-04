import Control.Monad

go :: [a] -> [a]
go (i:j:k) = j: i: go k
go i = i

main :: IO ()
main = do
  n <- readLn
  replicateM_ n $ do
    s <- getLine
    putStrLn $ go s