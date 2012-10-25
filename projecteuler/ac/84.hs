import Control.Arrow (second)
import Data.Array
import Data.Char (digitToInt)
import Data.List
import Data.Maybe (fromJust)
import Data.Ord (comparing)

-- parameter
dice = [1 .. 4]

monopoly = concatMap words [
  "GO A1 CC1 A2 T1 R1 B1 CH1 B2 B3",
  "JAIL C1 U1 C2 C3 R2 D1 CC2 D2 D3",
  "FP E1 CH2 E2 E3 R3 F1 F2 U2 F3",
  "G2J G1 G2 CC3 G3 R4 CH3 H1 T2 H2"]

sz = length monopoly

cell = (monopoly!!)
idx x = fromJust $ elemIndex x monopoly

jail = idx "JAIL"

cc i = map idx $ "GO": "JAIL": replicate 14 self
  where
    self = "CC" ++ show i

ch i = map idx $ "GO": "JAIL": "C1": "E3": "H2": "R1": nr: nr: nu: cell (idx self - 3): replicate 6 self
  where
    self = "CH" ++ show i
    nr = ["R2", "R3", "R1"] !! pred i
    nu = ["U1", "U2", "U1"] !! pred i

-- transfer
status = [(i, j) | i <- [0 .. sz-1], j <- [0 .. 2]]

matrix = accumArray (+) 0 (((0, 0), (0, 0)), ((sz-1, 2), (sz-1, 2))) $
  [((j, i), k) | i <- status, (j, k) <- from i]
  where
    normalize x = fmap (second (/fromIntegral (length x))) $ concat x
    from (a, b) = normalize [to (mod (a + i + j) sz) (if i == j then b + 1 else 0) | i <- dice, j <- dice]
    to c d =
      if d == 3
         then [((jail, 0), 1)]
         else case cell c of
                   ('G':'2':'J':_)  -> [((jail, d), 1)]
                   ('C':'C':k:_)    -> normalize [[((i, d), 1)] | i <- cc $ digitToInt k]
                   ('C':'H':k:_)    -> normalize [[((i, d), 1)] | i <- ch $ digitToInt k]
                   _                -> [((c, d), 1)]

-- solution
(#*) a b = [[sum $ zipWith (*) i j | j <- transpose b] | i <- a]

probabilities = accumArray (+) 0 (0, sz-1) [(fst i, average j) | (i, j) <- zip status minf]
  where
    average a = sum a / fromIntegral (length a)
    minf = (!!20) $ iterate (\i -> i #* i) $ [[matrix!(i,j) | j <- status] | i <- status]

main = do
  print $ reverse $ sortBy (comparing snd) $ assocs probabilities
