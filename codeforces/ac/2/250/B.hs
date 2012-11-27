import Control.Monad
import Data.List

split c = map (takeWhile (/=c) . tail) . filter ((==c) . head) . init . tails . (c:)

main = do
  n <- fmap read getLine
  replicateM_ n $ do
    (a, b) <- fmap (break (=="") . split ':') getLine
    let b' = filter (/="") b
        s = a ++ replicate (8 - length a - length b') "" ++ b'
    putStrLn $ intercalate ":" $ map (until ((>=4) . length) ('0':)) s
