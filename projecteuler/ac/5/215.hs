import Data.Bits
import qualified Data.IntMap.Strict as M

gen :: Int -> [Int] -> [[Int]]
gen limit step = concatMap (`go` []) step
  where
    go x y = case compare x limit of
               GT -> []
               EQ -> [y]
               _  -> concat [go (x + i) (x: y) | i <- step]

gao :: Int -> Int -> Integer
gao width height = M.foldr (+) 0 $ (!!(height-1)) $ iterate f $
    M.fromList $ zip ix $ repeat 1
  where
    ix = map (foldr (.|.) 0 . map bit) $ gen width [2, 3]
    f a = M.fromListWith (+) [(j, e) | (i, e) <- M.assocs a, j <- M.keys a, i .&. j == 0]

main :: IO ()
main = print $ gao 32 10
