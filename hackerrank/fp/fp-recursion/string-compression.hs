import Data.List

main = do
  s <- getLine
  let t = concat
        [ c: r
        | i@(c:_) <- group s
        , let n = length i
        , let r = if n > 1 then show n else ""
        ]
  putStrLn t