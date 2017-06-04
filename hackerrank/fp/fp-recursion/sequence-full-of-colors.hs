import Control.Monad

main :: IO ()
main = do
  n <- readLn
  replicateM_ n $ do
    s <- getLine
    let go rg yb [] = rg == 0 && yb == 0
        go rg yb (h:t) = case h of
          'R' -> rg <= 0 && go (rg+1) yb t
          'G' -> rg >= 0 && go (rg-1) yb t
          'Y' -> yb <= 0 && go rg (yb+1) t
          'B' -> yb >= 0 && go rg (yb-1) t
    print $ go 0 0 s