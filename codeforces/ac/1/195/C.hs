import Data.Char
import qualified Data.ByteString.Char8 as C

data Result
  = Ex C.ByteString
  | Msg C.ByteString
  | Nil
  | End
  deriving (Eq, Show)

type Parser = State C.ByteString

next :: (Char -> Bool) -> Parser C.ByteString
next f = do
  modify $ C.dropWhile $ not . f
  (x, y) <- gets $ C.span f
  put y
  return x

parseMany :: Parser Result
parseMany = do
  first <- parse
  if first == End
    then return Nil
    else do
      rest <- parseMany
      return $ if first /= Nil then first else rest

parse :: Parser Result
parse = do
  modify $ C.dropWhile $ not . isLetter
  h <- gets C.head
  if h /= 't'
    then return End
    else do
      key <- next $ isLetter
      if key == C.pack "throw"
        then do
          ex <- next $ isLetter
          return $ Ex ex
        else do
          result <- parseMany
          _ <- next $ isLetter    -- "catch"
          ex <- next $ isLetter
          _ <- next $ (=='"')
          msg <- next $ (/='"')
          if result == Ex ex
            then return $ Msg msg
            else return result

main :: IO ()
main = do
  _ <- C.getLine
  s <- C.getContents
  let ans = case fst $ runState parseMany $ C.append s $ C.pack " return" of
              Ex _ -> "Unhandled Exception"
              Msg msg -> C.unpack msg
              _ -> "Error"
  putStrLn ans

-- Control.Monad.State
newtype State s a = State {
  runState :: s -> (a, s)
}

instance Monad (State s) where
  return a = State $ \s -> (a, s)
  m >>= f  = State $ \s -> let (a', s') = runState m s in runState (f a') s'

get :: State s s
get = State $ \s -> (s, s)

put :: s -> State s ()
put s = State $ \_ -> ((), s)

modify :: (s -> s) -> State s ()
modify f = State $ \s -> ((), f s)

gets :: (s -> a) -> State s a
gets f = State $ \s -> (f s, s)

