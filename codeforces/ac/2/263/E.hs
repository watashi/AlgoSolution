{-# OPTIONS_GHC -O2 -optc-Ofast -ignore-asserts #-}
import Control.Monad
import Data.Array.IO
import Data.Array.Unboxed
import Data.Int
import Data.IORef
import Data.List
import Data.Maybe
import Data.Ord
import System.Exit
import qualified Data.ByteString.Char8 as C

type IA = UArray (Int, Int) Int64
type MA = IOUArray (Int, Int) Int64

accumulate :: Int -> Int -> Int -> IA -> IO IA
accumulate k dx dy a = do
  s <- thaw a :: IO MA
  let gets p = if inRange ix p then readArray s p else return 0
      geta p = if inRange ix p then a!p else 0
  forM_ r $ \i -> do
    forM_ c $ \j -> do
      t <- gets (i - dx, j - dy)
      writeArray s (i, j) $ t + geta (i, j) - geta (i - kdx, j - kdy)
  freeze s
  where
    kdx = k * dx
    kdy = k * dy
    ix@(begin, end) = bounds a
    r = let r' = [fst begin .. fst end] in if dx >= 0 then r' else reverse r'
    c = let c' = [snd begin .. snd end] in if dy >= 0 then c' else reverse c'

main :: IO ()
main = do
  [n, m, k] <- getArray
  a <- fmap (listArray ((1, 1), (n, m)) . map fromIntegral . concat) $ replicateM n $ getArray

  when (k == 1) $ do
    let ((x, y), _) = maximumBy (comparing snd) $ assocs a
    putStrLn $ show x ++ " " ++ show y
    exitSuccess

  sr <- accumulate (2 * k - 1) 0 1 a
  sc <- accumulate (2 * k - 1) 1 0 a
  sd <- accumulate k 1 1 a
  st <- accumulate (k - 1) 1 (-1) a

  let k' = k - 1
      k'' = k - 2
      shiftl (i, j) = sc!(i+k',j) - sd!(i+k',j-1) - st!(i-1,j-k''-1)
      shiftr (i, j) = sd!(i,j+k') + st!(i+k',j) - sc!(i+k',j-1)
      shiftu (i, j) = sr!(i,j+k') - sd!(i-1,j+k') - st!(i-1,j-k')
      shiftd (i, j) = sd!(i+k',j) + st!(i+k'',j+1) - sr!(i-1,j+k')
      shiftld (i, j) = sd!(i+k',j) - st!(i-1,j-k') - a!(i-k'-1,j)
      shiftrd (i, j) = st!(i+k',j) + a!(i,j+k') - sd!(i-1,j+k')

  diamond <- newIORef 0
  tril <- newIORef 0
  trir <- newIORef 0
  triu <- newIORef 0
  trid <- newIORef 0
  forM_ [1 .. 2 * k - 1] $ \i -> do
    forM_ [1 .. 2 * k - 1] $ \j -> do
      let d = k - abs (i - k) - abs (j - k)
          e = a!(i,j)
      when (d > 0) $ do
        modifyIORef' diamond (fromIntegral d * e +)
        when (j <= k) $ modifyIORef' tril (+e)
        when (j >= k) $ modifyIORef' trir (+e)
        when (i <= k) $ modifyIORef' triu (+e)
        when (i >= k) $ modifyIORef' trid (+e)

  best <- newIORef $ -1
  ans <- newIORef (0, 0)
  forM_ [k .. n - k + 1] $ \i -> do
    diamond' <- newIORef =<< readIORef diamond
    tril' <- newIORef =<< readIORef tril
    trir' <- newIORef =<< readIORef trir
    forM_ [k .. m - k + 1] $ \j -> do
      flag <- liftM2 (<) (readIORef best) (readIORef diamond')
      when flag $ do
        writeIORef best =<< readIORef diamond'
        writeIORef ans (i, j)
      when (j < m - k + 1) $ do
        modifyIORef' trir' (shiftr (i,j+1) +)
        diff <- liftM2 (-) (readIORef trir') (readIORef tril')
        modifyIORef' diamond' (+diff)
        modifyIORef' tril' (shiftl (i,j+1) +)
    when (i < n - k + 1) $ do
      modifyIORef' trid (shiftd (i+1,k) +)
      diff <- liftM2 (-) (readIORef trid) (readIORef triu)
      modifyIORef' diamond (+diff)
      modifyIORef' triu (shiftu (i+1,k) +)
      modifyIORef' tril (shiftld (i+1,k) +)
      modifyIORef' trir (shiftrd (i+1,k) +)

  (x, y) <- readIORef ans
  putStrLn $ show x ++ " " ++ show y
  where
    getArray = fmap (map (fst . fromJust . C.readInt) . C.words) C.getLine
