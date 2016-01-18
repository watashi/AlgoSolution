{-# LANGUAGE BangPatterns #-}

import Control.Applicative
import Control.Arrow
import Data.Bits
import Control.DeepSeq
import Control.Monad
import Control.Monad.Trans.State.Lazy
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Maybe
import Data.Word (Word64)
import qualified Data.IntMap.Strict as Map
import qualified Data.IntSet as Set
import qualified Data.ByteString.Char8 as C

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

type Word64Set = Map.IntMap Set.IntSet

pack64 :: Int -> Int -> Word64
pack64 i j =
  (fromIntegral i `unsafeShiftL` 31) .|. (fromIntegral j .&. 0x7fffffff)

unpack64 :: Word64 -> (Int, Int)
unpack64 k =
  (fromIntegral $ k `unsafeShiftR` 31, fromIntegral $ k .&. 0x7fffffff)

fromList64 :: [Word64] -> Word64Set
fromList64 = Map.fromListWith Set.union . map (second Set.singleton . unpack64)

minView64 :: Word64Set -> Maybe (Word64, Word64Set)
minView64 m = Just
  ( pack64 i j
  , Map.updateMin (\_ -> if Set.null s then Nothing else Just s) m
  )
  where
  (i, v) = Map.findMin m
  (j, s) = fromJust $ Set.minView v

insert64 :: Word64 -> Word64Set -> Word64Set
insert64 k = Map.insertWith Set.union i $ Set.singleton j
  where
  (i, j) = unpack64 k

wash :: Int -> [Word64] -> [Word64]
wash n w = gao n [] `evalState` s
  where
  m = fromIntegral $ length w :: Word64
  d = listArray (0, m - 1) w :: UArray Word64 Word64
  s = fromList64 $ map pack $ zip w [0..]

  pack (i, j) = i * m + j
  unpack k = k `quotRem` m

  gao 0  !acc = return $! reverse acc
  gao !k !acc = do
    (t, i) <- state $ first unpack . fromJust . minView64
    modify $ insert64 (pack (t + d!i, i))
    gao (k-1) (t: acc)

dry :: Int -> Word64 -> [Word64] -> [Word64]
dry !n !d !s = elems t
  where
  (sl, sr) = splitAt n s

  t :: Array Int Word64
  t = listArray (0, length s - 1) $
    map (+d) sl ++ [max e (t!i) + d | (i, e) <- zip [0..] sr]

solve :: (Int, [Int], Int, Int) -> Word64
solve (n, w, m, d) = last $ dry m (fromIntegral d) $ wash n (map fromIntegral w)

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  forM_ [1 .. re] $ \ri -> do
    (n:_:m:d:_) <- map readInt . C.words <$> C.getLine
    w <- map readInt . C.words <$> C.getLine
    let ans = solve (n, w, m, d)
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
