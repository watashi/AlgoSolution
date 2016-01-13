{-# LANGUAGE MultiWayIf #-}

import Control.Monad hiding (guard)
import Control.Parallel.Strategies
import Data.List
import Data.Maybe
import qualified Data.Map.Strict as Map
import qualified Data.ByteString.Char8 as C

data Status
  = NONE
  | TODO
  | DONE
  deriving (Bounded, Enum, Eq, Ord, Show)

readInt :: C.ByteString -> Int
readInt = fst . fromJust . C.readInt

solve :: (Int, C.ByteString, C.ByteString) -> Int
solve (_, a, b) = minimum
  [ dp
  | ((sx, sy), dp) <- Map.toList dpn
  , sx /= TODO
  , sy /= TODO
  ]
  where
  unpack s = [c /= '.' | c <- C.unpack s]
  dp0 = Map.singleton (NONE, NONE) 0
  dpn = foldl' next dp0 $ unpack a `zip` unpack b
  next cur (ox, oy) = Map.fromListWith min
    [ ((tx, ty), dp + if gx || gy then 1 else 0)
    | ((sx, sy), dp) <- Map.toList cur
    , (gx, gy) <- [(False, False), (False, True), (True, False)]
    , tx <- gao sx ox gx gy
    , ty <- gao sy oy gy gx
    ]

  gao s occupied guarded guarded2 = maybeToList $ do
    t <- if
      | occupied && guarded -> Nothing
      | guarded2 && not occupied -> Just s
      | otherwise -> occupy occupied s
    return $ guard guarded t

  occupy True TODO = Nothing
  occupy True _ = Just NONE
  occupy False NONE = Just TODO
  occupy False s = Just s

  guard True TODO = DONE
  guard _ s = s

main :: IO ()
main = do
  re <- readInt <$> C.getLine
  inputs <- replicateM re getInput
  let outputs = runEval $ parList rdeepseq $ map solve inputs
  forM_ ([1 .. re] `zip` outputs) $ \(ri, ans) -> do
    putStrLn $ "Case #" ++ show ri ++ ": " ++ show ans
  where
  getInput = do
    n <- readInt <$> C.getLine
    a <- C.take n <$> C.getLine
    b <- C.take n <$> C.getLine
    return (n, a, b)
