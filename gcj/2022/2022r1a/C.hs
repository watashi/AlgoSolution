import Control.Monad
import Data.Array
import qualified Data.ByteString.Char8 as C
import Text.Printf

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    (e:_w:_) <- map readInt . C.words <$> C.getLine
    xs <- replicateM e $ map readInt . C.words <$> C.getLine
    let
      ix = ((0, 0), (e-1, e-1))
      c = accumArray (\_ i -> i) (-1) ix
        [ ((i, j), sum k)
        | i <- [0 .. e-1]
        , (j, k) <- [i ..] `zip` scanl1 (zipWith min) (drop i xs)
        ]
      dp = listArray ix [gao i j | (i, j) <- range ix]
      gao l r
        | l > r = -1
        | l == r = c!(l,r) * 2
        | otherwise = minimum
          [ dp!(l,m) + dp!(m+1,r) - cc * 2
          | m <- [l .. r - 1]
          ]
        where
          cc = c!(l,r)
    {-
    forM_ [0..e-1] $ \i ->
      forM_ [i..e-1] $ \j ->
        printf "[%d][%d] = (%d, %d)\n" i j (c!(i,j)) (dp!(i,j))
    -}
    printf "Case #%d: %d\n" ri $ gao 0 $ e - 1
  where
    readInt s = let Just (i, _) = C.readInt s in i :: Int
