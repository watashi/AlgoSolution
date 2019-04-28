import Control.Monad
import Data.Array
import Data.List

digits :: [(Char, Char, String)]
digits =
  [ ('Z', '0', "ZERO")
  , ('U', '4', "FOUR")
  , ('R', '3', "THREE")
  , ('G', '8', "EIGHT")
  , ('X', '6', "SIX")
  , ('F', '5', "FIVE")
  , ('S', '7', "SEVEN")
  , ('T', '2', "TWO")
  , ('I', '9', "NINE")
  , ('O', '1', "ONE")
  ]

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    input <- getLine
    let buildA = accumArray (+) 0 ('A', 'Z')
        count = buildA $ input `zip` repeat 1
        go [] _ = ""
        go ((c, d, s): t) a = replicate n d ++ go t a'
          where
          n = a!c
          a' = listArray ('A', 'Z') $
            zipWith (-) (elems a) (elems $ buildA $ s `zip` repeat n)
        ans = sort $ go digits count
    putStrLn $ "Case #" ++ show ri ++ ": " ++ ans
