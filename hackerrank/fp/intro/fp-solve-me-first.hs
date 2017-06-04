import Control.Applicative

main :: IO ()
main = print =<< (+) <$> readLn <*> readLn