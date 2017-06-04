{-# LANGUAGE OverloadedStrings #-}

import Control.Applicative
import Control.Monad
import Data.ByteString (ByteString)
import Data.Maybe
import qualified Data.ByteString.Char8 as C

gao :: [ByteString] -> ByteString -> Maybe [ByteString]
gao w s = head $ foldr gen [Just []] $ init $ C.tails s
  where
  gen suffix dp = flip (:) dp $ listToMaybe
    [ i: solution
    | i <- w
    , i `C.isPrefixOf` suffix
    , Just solution <- [dp !! (C.length i - 1)]
    ]

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    _ <- getLine
    w <- map C.pack . words <$> getLine
    s <- C.pack <$> getLine
    case gao w s of
      Just ans -> C.putStrLn $ C.unwords ans
      Nothing -> C.putStrLn "WRONG PASSWORD"