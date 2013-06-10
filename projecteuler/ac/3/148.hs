-- Lucas' theorem

base :: Integral a => a
base = 7

digits :: Integral a => a -> [a]
digits = map (`rem` base) . takeWhile (>0) . iterate (`quot`base)

count :: Integral a => a -> a
count = product . map succ . digits

gao :: Integral a => a -> a
gao n = go $ reverse $ zip [(0::Int)..] $ digits n
  where
    c2 x = succ x * x `quot` 2
    go [] = 0
    go ((p,d):t) = c2 d * c2 base ^ p + succ d * go t

main :: IO ()
main = print $ gao $ (1000000000::Integer)
