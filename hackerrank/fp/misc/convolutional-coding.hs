import Control.Applicative
import Control.Monad
import Data.Array
import Data.Bits
import Data.ByteString (ByteString)
import qualified Data.ByteString.Builder as B
import qualified Data.ByteString.Char8 as C
import qualified Data.ByteString.Lazy as L
import Data.Monoid

data Config = Config
  { cfgN :: Int
  , cfgK :: Int
  , cfgP :: [Int]
  } deriving (Show)

readBits :: ByteString -> Int
readBits = C.foldr (\i j -> fromEnum (i /= '0') .|. j `unsafeShiftL` 1) 0

showBits :: Int -> Int -> ByteString
showBits n = fst . C.unfoldrN n f
  where
  f i = Just (if testBit i 0 then '1' else '0', i `unsafeShiftR` 1)

readConfig :: IO Config
readConfig = do
  (n:k:_) <- map readInt . C.words <$> C.getLine
  p <- replicateM n $ readBits <$> C.getLine
  return $ Config n k p
  where
  readInt s = let Just (i, _) = C.readInt s in i

chunkOf :: Int -> ByteString -> [ByteString]
chunkOf n s = map (C.take n) $ takeWhile (not . C.null) $ iterate (C.drop n) s

encode1 :: Config -> Int -> Int
encode1 (Config _ _ p) s =
  foldr (\i j -> parity (i .&. s) .|. j `unsafeShiftL` 1) 0 p
  where
  parity n = popCount n .&. 1

encode :: Config -> ByteString -> ByteString
encode cfg@(Config n k _) s = C.concat
  [ showBits n $ encode1 cfg $ readBits $ C.reverse $ C.take k i
  | i <- takeWhile ((>=k) . C.length) $ C.tails $ C.tail $ pad <> s <> pad
  ]
  where
  pad = C.replicate k '0'

decode :: Config -> ByteString -> ByteString
decode cfg@(Config n k _) s = C.take (C.length ans - k) ans
  where
  ans = L.toStrict $ B.toLazyByteString $ snd (headA!0)
  tokens = map readBits $ chunkOf n s
  buildA = listArray (0 :: Int, bit k - 1)
  codes = buildA $ map (encode1 cfg) [0..]
  lastA = buildA $ (0, mempty): repeat (maxBound `quot` 3, mempty)
  headA = foldr gao lastA $ [0::Int ..] `zip` tokens
  gao (idx, token) a = buildA
    [ ( popCount (xor token $ codes!i) + penalty + fst (a!j)
      , B.char7 (if i .&. 1 == 0 then '0' else '1') <> snd (a!j)
      )
    | i <- [0..]
    , let j0 = clearBit (i `unsafeShiftL` 1) k
    , let j1 = j0 .|. 1
    , let j = if fst (a!j0) <= fst (a!j1) then j0 else j1
    , let penalty = if idx .&. 7 == 0 && i .&. 1 == 1 then 80 * n else 0
    ]

main :: IO ()
main = do
  decodeConfig <- readConfig
  encodeConfig <- readConfig
  msg <- C.filter (\i -> i == '0' || i == '1') <$> C.getContents
  let ans = encode encodeConfig $ decode decodeConfig msg
  C.putStrLn ans
