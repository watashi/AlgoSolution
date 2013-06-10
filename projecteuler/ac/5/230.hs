data Fib
  = Atom {
      size :: Integer,
      fstr :: String
    }
  | Cons {
      size :: Integer,
      fpre :: Fib,
      fsuf :: Fib
    }

atom :: String -> Fib
atom s = Atom (toInteger $ length s) s

cons :: Fib -> Fib -> Fib
cons a b = Cons (size a + size b) a b

at :: Fib -> Integer -> Char
at (Atom _ s) i = s!!fromInteger i
at (Cons _ a b) i = let m = size a in if i < m then a `at` i else b `at` (i - m)

fib :: String -> String -> [Fib]
fib a b = let me = atom a: atom b: zipWith cons me (tail me) in me

main :: IO ()
main = do
  putStrLn $ reverse $ map gao [0 .. 17]
  where
    a = "14159265358979323846264338327950288419716939937510" ++
        "58209749445923078164062862089986280348253421170679"
    b = "82148086513282306647093844609550582231725359408128" ++
        "48111745028410270193852110555964462294895493038196"
    d = fib a b
    gao n = str `at` off
      where
        off = pred $ (127 + 19 * n) * (7 ^ n)
        str = head $ dropWhile ((<= off) . size) d
