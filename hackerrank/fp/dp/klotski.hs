import Control.Arrow
import Control.Applicative
import Control.Monad.Trans.State.Strict
import Control.Monad
import Data.Array.IArray
import Data.Array.Unboxed
import Data.Bits
import Data.ByteString (ByteString)
import qualified Data.ByteString as BS
import qualified Data.IntSet as Set
import Data.HashMap.Strict (HashMap)
import qualified Data.HashMap.Strict as Map
import Data.List
import Data.Maybe
import Data.Tuple
import Data.Word
import Debug.Trace

decodePos :: Int -> (Int, Int)
decodePos i = quotRem i 8

encodePos :: (Int, Int) -> Int
encodePos (x, y) = x * 8 + y

bitwiseOr :: [Word64] -> Word64
bitwiseOr = foldl' (.|.) 0

move :: Word64 -> Int -> Word64
move block by = block `shift` by

unmove :: Word64 -> (Word64, Int)
unmove block = (block `shift` negate by, by)
  where
  by = encodePos $ minimum *** minimum $ unzip
    [ decodePos i
    | i <- [0 .. 63]
    , testBit block i
    ]

diff :: ByteString -> ByteString -> (Int, (Int, Int), (Int, Int))
diff a b = (k, pos a, pos b)
  where
  pos c = decodePos $ fromIntegral $ BS.index c k
  k = until (\i -> BS.index a i /= BS.index b i) succ 0

gen :: Word64 -> Word64 -> Word8 -> [Word8]
gen board block start =
  map fromIntegral $ Set.toList $ go (fromIntegral start) `execState` Set.empty
  where
  go s = do
    done <- gets $ Set.member s
    if done then return () else do
    modify $ Set.insert s
    forM_ [s + 1, s - 1, s + 8, s - 8] $ \t ->
      when (board .&. move block t == 0) $
        go t

gao :: Word64
    -> UArray Int Word64
    -> (ByteString -> ByteString)
    -> ByteString
    -> Word8
    -> (ByteString, HashMap ByteString ByteString)
gao boundary blocks normalize start end =
  go [start] `runState` Map.singleton start BS.empty
  where
  n = BS.length start
  go [] = error "no answer"
  go current = case filter ((==end) . BS.head) current of
    (target:_) -> return target
    [] -> do
      traceM $ show $ length current
      todos <- forM current $ \from -> do
        -- traceM $ show $ BS.unpack from
        let block i = move (blocks!i) (fromIntegral $ BS.index from i)
            board = bitwiseOr $ boundary: map block [0..n-1]
        forM [0..n-1] $ \idx -> do
          let board' = board `xor` block idx
          forM (gen board' (blocks!idx) (BS.index from idx)) $ \val -> do
            let to = BS.append (BS.take idx from) $
                  BS.cons val $ BS.drop (idx + 1) from
                to' = normalize to
            done <- gets $ Map.member to'
            if done then return Nothing else do
            modify $ Map.insert to' from
            return $ Just to
      go $ concatMap (concatMap catMaybes) todos

main :: IO ()
main = do
  (r:c:_) <- map read . words <$> getLine
  cells <- replicateM r $
    words <$> getLine
  target <- getLine
  (tx:ty:_) <- map read . words <$> getLine
  let boundary = bitwiseOr
        [ bit $ encodePos (i, j)
        | i <- [0 .. 7]
        , j <- [0 .. 7]
        , not $ 1 <= i && i <= r && 1 <= j && j <= c
        ]
      cellToBlock = Map.fromListWith (.|.)
        [ (cell, bit $ encodePos (i, j))
        | (i, row) <- [1..] `zip` cells
        , (j, cell) <- [1..] `zip` row
        , not $ all (=='.') cell
        ]
      ([(targetInfo, _)], otherInfos) =
        second (groupBy (\((i, _), _) ((j, _), _) -> i == j) . sort) $
        partition ((==target) . snd) $
        map swap $ Map.toList $ fmap unmove $ cellToBlock
      names = target: concatMap (map snd) otherInfos
      (blocks', start') = unzip $ targetInfo: concatMap (map fst) otherInfos
      blocks = listArray (0, length blocks' - 1) blocks'
      start = BS.pack $ map fromIntegral start'
      end = fromIntegral $ encodePos (tx + 1, ty + 1)
      normalize bs = BS.pack $ concatMap (sort . map (BS.index bs)) $ groups
        where
        nameToIndex = Map.fromList $ names `zip` [0..]
        groups = map (nameToIndex Map.!) <$> [target]: map (map snd) otherInfos
      (final, pre) = gao boundary blocks normalize start end
      path = takeWhile (not . BS.null) $ iterate ((pre Map.!) . normalize) final
  traceM $ show $ BS.unpack start
  traceM $ show [end]
  print $ length path - 1
  forM_ (reverse $ zipWith diff path $ tail path) $ \(i, to, from) ->
    putStrLn $ unwords [names!!i, showPos from, showPos to]
  where
  showPos (x, y) = show (x - 1, y - 1)
