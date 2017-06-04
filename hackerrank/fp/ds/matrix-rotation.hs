import Data.Array.Unboxed
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  (r:c:n:a) <- fmap (map readInt . C.words) C.getContents
  let from, to :: UArray (Int, Int) Int
      from = listArray ((1, 1), (r, c)) a
      to = array ((1, 1), (r, c))
        [ (j, from!i)
        | k <- [1 .. min r c `quot` 2]
        , let chain = concat
                [ [(x, k) | x <- [k .. r - k]]
                , [(r - k + 1, y) | y <- [k .. c - k]]
                , [(x, c - k + 1) | x <- [r - k + 1, r - k .. k + 1]]
                , [(k, y) | y <- [c - k + 1, c - k .. k + 1]]
                ]
              chain' = rotateBy n chain
        , (i, j) <- chain `zip` chain'
        ]
  putStr $ unlines [unwords [show $ to!(i, j) | j <- [1 .. c]] | i <- [1 .. r]]
  where
  readInt s = let Just (i, _) = C.readInt s in i
  rotateBy n a = let (l, r) = splitAt (n `mod` length a) a in r ++ l
  