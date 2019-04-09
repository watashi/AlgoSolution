{-# LANGUAGE BangPatterns #-}

import Control.Monad
import Data.Bits
import Data.Char
import Data.List
import System.IO

main :: IO ()
main = do
  re <- readLn
  replicateM_ re $ do
    (n:_) <- map read . words <$> getLine
    forM_ [4, 3 .. 0] $ \i ->
      putStrLn $ take n $ [if testBit j i then '1' else '0' | j <- enumFrom (0 :: Int)]
    hFlush stdout
    (t4:ts) <- replicateM 5 $ filter isDigit <$> getLine
    let result = filter (<n) $ checkAll 0 ts $ map length $ group t4
    putStrLn $ unwords $ map show result
    hFlush stdout
    _ <- getLine -- "1\n"
    return ()
  where
  checkAll :: Int -> [String] -> [Int] -> [Int]
  checkAll _ _ [] = []
  checkAll !start ts (chunk:chunks) =
    (if chunk < 16 then checkOne start 3 $ map (take chunk) ts else []) ++
    checkAll (start+16) (drop chunk <$> ts) chunks

  checkOne :: Int -> Int -> [String] -> [Int]
  checkOne !start _ [] = [start]
  checkOne !start !n (chunk: chunks) =
    (if zeros < total
      then checkOne start (n-1) (map (take zeros) chunks)
      else []) ++
    (if ones < total
      then checkOne (start+total) (n-1) (map (drop zeros) chunks)
      else [])
    where
    zeros = length $ filter (=='0') chunk
    ones = length $ filter (=='1') chunk
    total = bit n
