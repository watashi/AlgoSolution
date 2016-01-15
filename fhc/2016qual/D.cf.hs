import Control.Applicative
import Control.Monad
import Data.Char
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

lcp :: C.ByteString -> C.ByteString -> Int
lcp a b = until differentAt succ 0
  where
  differentAt i =
    i == C.length a || i == C.length b || C.index a i /= C.index b i

solve :: (Int, [C.ByteString]) -> Int
solve (k, w) = k + minimum dpk
  where
  w' = sort w
  lens = map C.length w'
  lcps = zipWith lcp w' $ tail w'
  next cur = init
    [ 2 * m + minimum zs
    | (m, xs, ys) <- zip3 lens (tails lcps) (tail $ tails cur)
    , let zs = zipWith (\x y -> y - 2 * x) (scanl1 min xs) ys
    ]
  dp1 = map (2 *) lens
  dpk = iterate next dp1 !! (k-1)

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    (n:k:_) <- map readInt . C.words <$> C.getLine
    a <- replicateM n $ C.takeWhile isAsciiLower <$> C.getLine
    return (k, a)
