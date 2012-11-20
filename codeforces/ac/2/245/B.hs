gao "ru" = ".ru"
gao ('r':'u':t) = ".ru/" ++ t
gao (h:t) = h: gao t

main = do
  input <- getLine
  case input of
    'f':'t':'p':h:t -> putStrLn $ "ftp://" ++ h:gao t
    'h':'t':'t':'p':h:t -> putStrLn $ "http://" ++ h:gao t
