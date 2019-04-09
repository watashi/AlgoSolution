import Control.Monad

main :: IO ()
main = do
  re <- readLn
  forM_ [(1 :: Int) .. re] $ \ri -> do
    _ <- getLine
    s <- filter (`elem` "SE") <$> getLine
    putStrLn $ "Case #" ++ show ri ++ ": " ++ gao 0 0 'X' s
  where
  gao ns ne c rest | ns > 0 && ns == ne =
    replicate ns c ++ replicate ns (if c == 'S' then 'E' else 'S') ++ gao 0 0 'X' rest
  gao ns ne _ ('S': rest) = gao (ns + 1) ne 'S' rest
  gao ns ne _ ('E': rest) = gao ns (ne + 1) 'E' rest
  gao 0 0 'X' "" = ""
  gao _ _ _ _ = undefined
