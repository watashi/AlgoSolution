{-# LANGUAGE DataKinds #-}
{-# LANGUAGE DeriveDataTypeable #-}
{-# LANGUAGE GeneralizedNewtypeDeriving #-}
{-# LANGUAGE KindSignatures #-}

import Control.Applicative hiding (many)
import Control.Exception
import Control.Monad
import Control.Monad.IO.Class
import Control.Monad.Trans.State.Strict
import Data.Char
import Data.Functor
import Data.IntMap.Strict (IntMap)
import qualified Data.IntMap.Strict as Map
import Data.Typeable
import GHC.TypeLits
import Text.ParserCombinators.ReadP

newtype MIntT i (n :: Nat) = MInt i
  deriving (Enum, Eq)

instance Show i => Show (MIntT i n) where
  show (MInt a) = show a

modulo :: (KnownNat n, Num i) => MIntT i n -> i
modulo = fromInteger . natVal

mint :: (KnownNat n, Integral i) => i -> MIntT i n
mint a = let m = MInt $ a `mod` modulo m in m

instance (KnownNat n, Integral i) => Num (MIntT i n) where
  (+) m@(MInt a) (MInt b) =
    let c = a + b in MInt $ if c >= modulo m then c - modulo m else c
  (-) m@(MInt a) (MInt b) =
    let c = a - b in MInt $ if c >= 0 then c else c + modulo m
  (*) m@(MInt a) (MInt b) = MInt $ a * b `rem` modulo m
  abs = error "abs"
  negate m@(MInt a) = if a == 0 then 0 else MInt $ modulo m - a
  signum = error "signum"
  fromInteger a = let m = MInt $ fromInteger (a `mod` natVal m) in m

type MInt = MIntT Int 256

data Status = Status
  { memory :: IntMap MInt
  , pointer :: Int
  , input :: String
  , counter :: Int
  }

type Eval a = StateT Status IO a

data OperationLimitExceeded = OperationLimitExceeded
  deriving (Show, Typeable)

instance Exception OperationLimitExceeded

cur :: Eval MInt
cur = gets $ \s -> Map.findWithDefault 0 (pointer s) (memory s)

ticked :: Eval a -> Eval a
ticked f = do
  c <- state $ \s -> let c = counter s in (c, s{ counter = c - 1 })
  when (c <= 0) $ liftIO $ throwIO OperationLimitExceeded
  f

mov :: Int -> Eval ()
mov x = ticked $ modify $ \s -> s{ pointer = pointer s + x }

add :: MInt -> Eval ()
add x = ticked $ modify $ \s -> s
  { memory = Map.insertWith (+) (pointer s) x (memory s)
  }

putc :: Eval ()
putc = liftIO . putChar . chr . fromEnum =<< ticked cur

getc :: Eval ()
getc = ticked $ modify $ \s@Status{ input = c: cs } -> s
  { memory = Map.insert (pointer s) (mint $ ord c) (memory s)
  , input = cs
  }

loop :: Eval () -> Eval ()
loop body = do
  i <- ticked cur
  when (i /= 0) body
  j <- ticked cur
  when (j /= 0) $ loop body

brainfuck :: ReadP (Eval ())
brainfuck = sequence_ <$> many stmt
  where
  stmt = foldl1 (<++)
    [ char '>' $> mov 1
    , char '<' $> mov (negate 1)
    , char '+' $> add 1
    , char '-' $> add (negate 1)
    , char '.' $> putc
    , char ',' $> getc
    , loop <$> (char '[' *> brainfuck <* char ']')
    ]

main :: IO ()
main = do
  _ <- getLine
  i <- getLine
  p <- filter (`elem` "><+-.,[]") <$> getContents
  let [(bf, "")] = readP_to_S (brainfuck <* eof) p
  handle (\OperationLimitExceeded -> putStr "\nPROCESS TIME OUT. KILLED!!!") $
    bf `evalStateT` Status
      { memory = Map.empty
      , pointer = 0
      , input = i
      , counter = 100000 
      }
