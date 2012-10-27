f x = (* 1.0e-9) $ fromIntegral $ floor $ 2 ** (30.403243784 - x ** 2)

main = print $ sum $ take 2 $ drop 1000 $ iterate f $ -1
