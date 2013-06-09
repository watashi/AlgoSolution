{-# LANGUAGE CPP #-}
import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as C

interact' :: (C.ByteString -> String) -> IO ()
#ifndef __WATASHI__
interact' = hInteract "positive.in" "positive.out"

hInteract :: FilePath -> FilePath -> (C.ByteString -> String) -> IO ()
hInteract input output f =
  liftM f (C.readFile input) >>= writeFile output
#else
interact' = interact . (. C.pack)
#endif

main :: IO ()
main = interact' $ \input ->
  let (n:a) = map readInt $ C.words $ input in
  (++"\n") $ show $ max 0 $ (n-) $ (2*) $ length $ filter (<0) $ a
  where
    readInt = fst . fromJust . C.readInt
