import Control.Monad
import Data.Array (Array)
import Data.Array.Unboxed
import Data.Bits
import qualified Data.IntSet as IntSet
import Data.List
import Text.Printf

main :: IO ()
main = do
  re <- readLn
  forM_ [1 :: Int .. re] $ \ri -> do
    (row:col:_) <- map read . words <$> getLine
    grid <- replicateM row $ map (fromEnum . (=='#')) . take col <$> getLine
    let sumr, sumc :: UArray (Int, Int) Int
        sumr = listArray ((0, 0), (row - 1, col)) $ concat $ map (scanl (+) 0) grid
        sumc = listArray ((0, 0), (col - 1, row)) $ concat $ map (scanl (+) 0) $ transpose grid
        sg :: Array (Int, Int, Int, Int) Int
        sg = listArray ((0, 0, 0, 0), (row, col, row, col)) $
          [ fst $ gao r1 c1 r2 c2
          | r1 <- [0 .. row]
          , c1 <- [0 .. col]
          , r2 <- [0 .. row]
          , c2 <- [0 .. col]
          ]
        gao r1 c1 r2 c2
          | r1 == r2 = (0, 0)
          | c1 == c2 = (0, 0)
          | otherwise =
              ( head $ filter (`IntSet.notMember` sgs) [0..]
              , sum [count | (0, count) <- moves]
              )
          where
          sgs = IntSet.fromList $ map fst moves
          moves =
            [ (sg!(r1,c1,i,c2) `xor` sg!(i+1,c1,r2,c2), c2 - c1)
            | i <- [r1 .. r2 - 1]
            , sumr!(i,c1) == sumr!(i,c2)
            ] ++
            [ (sg!(r1,c1,r2,j) `xor` sg!(r1,j+1,r2,c2), r2 - r1)
            | j <- [c1 .. c2 - 1]
            , sumc!(j,r1) == sumc!(j,r2)
            ]
    printf "Case #%d: %d\n" ri $ snd $ gao 0 0 row col
