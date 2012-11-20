{-# OPTIONS_GHC -O2 -optc-Ofast -fignore-asserts #-}
import Data.Array.Unboxed (UArray, array, (!))
import Data.Maybe (fromJust)
import Debug.Trace (trace)
import qualified Data.ByteString.Char8 as C

doy :: UArray (Int, Int) Int
doy = array ((1,1), (12,31)) $ zip mmdd $ map (*day) [0 ..]
  where
    dom = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    day = 24 * 60 * 60
    mmdd = [(m, d) | (m, n) <- zip [1 .. ] dom, d <- [1 .. n]]

newtype State a = State {
    runState :: C.ByteString -> (a, C.ByteString)
  }

instance Monad State where
  return a = State $ \st -> (a, st)
  m >>= f  = State $ \st -> let (a', st') = runState m st in runState (f a') st'

get = State $ \st -> (st, st)
modify f = State $ \st -> ((), f st)

parse :: State Int
parse = do
  modify $ C.drop 4
  mm <- readInt
  dd <- readInt
  h <- readInt
  m <- readInt
  s <- readInt
  -- trace (show (mm, dd, h, m, s)) $
  return $ doy!(mm,dd) + (h * 60 + m) * 60 + s
  where
    readInt = State $ fromJust . C.readInt . C.tail

gao n m a = go b $ drop (m - 1) b
  where
    b = map (\i -> (fst $ runState parse i, i)) a
    go _ [] = "-1"
    go (a:ax) (b:bx) =
      if fst b - fst a < n
        then C.unpack $ C.take 19 $ snd b
        else go ax bx

main = do
  [n, m] <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
  logs <- fmap C.lines $ C.getContents
  putStrLn $ gao n m logs

