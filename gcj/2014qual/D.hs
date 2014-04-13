import Control.Monad
import Data.Function
import Data.Scientific
import qualified Data.Set as S
import Text.Printf

type MassSet = S.Set Scientific

playWar, playDeceitfulWar :: MassSet -> MassSet -> Int

playWar a b = S.size b'
  where
  b' = S.foldl' (flip deleteGT) b a
  deleteGT key set = maybe set (`S.delete` set) $ S.lookupGT key set

playDeceitfulWar a b
  | and $ (zipWith (>) `on` S.toList) a b = S.size a
  | otherwise = playDeceitfulWar (S.deleteMin a) (S.deleteMax b)

main :: IO ()
main = do
  re <- fmap read getLine
  forM_ [1::Int .. re] $ \ri -> do
    _ <- getLine
    a <- getMassSet
    b <- getMassSet
    printf "Case #%d: %d %d\n" ri (playDeceitfulWar a b) (playWar a b)
  where
  getMassSet = fmap (S.fromList . map read . words) getLine

