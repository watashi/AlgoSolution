{-# LANGUAGE MagicHash #-}
import Control.Applicative
import Control.Monad
import Control.Monad.Trans.State
import Data.Bits (bit)
import Data.Int (Int64)
import qualified Data.Map.Strict as M
import GHC.Base
import GHC.Integer.Logarithms
import Text.Printf

bitLength :: Int -> Int
bitLength (I# n) = I# (wordLog2# (unsafeCoerce# n))

gao :: Int -> Int -> Int -> State (M.Map (Int, Int, Int) Int64) Int64
gao a b c
  | c > a || c > b = gao a b $ min a b
  | a < 0 || b < 0 || c < 0 = return 0
  | a == c && b == c = return $ (fromIntegral a + 1) * (fromIntegral b + 1)
  | otherwise = do
      cache <- gets $ M.lookup (a, b, c)
      case cache of
        Just result -> return result
        Nothing -> do
          let d = bit . bitLength $ max a b
              a' = min a $ d - 1
              b' = min b $ d - 1
          result <- sum <$> sequence
            [ gao a' b' c
            , gao a' (b - d) c
            , gao (a - d) b' c
            , gao (a - d) (b - d) (c - d)
            ]
          modify $ M.insert (a, b, c) result
          return result

main :: IO ()
main = do
  re <- read <$> getLine
  forM_ [1::Int .. re] $ \ri -> do
    (a:b:c:_) <- map read . words <$> getLine
    printf "Case #%d: %d\n" ri $ gao (a - 1) (b - 1) (c - 1) `evalState` M.empty
