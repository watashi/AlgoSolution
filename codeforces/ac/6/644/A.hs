main :: IO ()
main = do
  (n:a:b:_) <- fmap (map read . words) getLine
  if n > a * b
  then print (-1)
  else flip mapM_ [0 .. a-1] $ \i -> do
    let r = (if even b && odd i then reverse else id)
          [if j < n then j + 1 else 0 | j <- take b [i * b ..]]
    putStrLn $ unwords $ map show r
