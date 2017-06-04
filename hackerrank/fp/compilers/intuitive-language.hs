import Control.Applicative hiding (many, optional)
import Control.Monad
import Control.Monad.IO.Class
import Control.Monad.Trans.State.Strict
import Data.Char
import Data.List
import Data.Map.Strict (Map)
import Data.Ratio
import qualified Data.Map.Strict as Map
import Text.ParserCombinators.ReadP hiding (char, string, munch, munch1)
import qualified Text.ParserCombinators.ReadP as ReadP

type Fraction = Ratio Int
newtype Function = Function [Fraction]

instance Show Function where
  show (Function (y:a)) = intercalate ", " $ map showCoefficient $ a ++ [y]
    where
    showCoefficient c = case (denominator c, numerator c) of
      (1, n) -> show n
      (d, n) -> show n ++ "/" ++ show d

fapply :: Function -> Fraction -> Function
fapply (Function (y:a:as)) x = let y' = y + a * x in Function (y': as)

fvalue :: Function -> Fraction
fvalue (Function [y]) = y

type Eval a = StateT (Map String Function) IO a

getf :: String -> Eval Function
getf f = gets $ (Map.! f)

setf :: String -> [Eval Fraction] -> Eval ()
setf f as = do
  as' <- sequence as
  modify $ Map.insert f $ Function $ last as': init as'

repf :: Eval Fraction -> Eval () -> Eval ()
repf n k = flip replicateM_ k =<< fmap floor n

char :: Char -> ReadP Char
char c = skipSpaces *> ReadP.char c

string :: String -> ReadP String
string s = skipSpaces *> ReadP.string s

munch, munch1 :: (Char -> Bool) -> ReadP String
munch p = skipSpaces *> ReadP.munch p
munch1 p = skipSpaces *> ReadP.munch1 p

name :: ReadP String
name = (++) <$> munch1 isLetter <*> munch isDigit

expression :: ReadP (Eval Fraction)
expression = foldl app <$> term <*> many ((,) <$> addOrSub <*> term)
  where
  term = foldl app <$> factor <*> many ((,) <$> mulOrDiv <*> factor)
  factor = foldl1 (<++)
    [ char '(' *> expression <* char ')'
    , return . fromInteger <$> readS_to_P reads
    , fmap fvalue <$> fexpression
    ]
  app i (op, j) = op <$> i <*> j
  addOrSub = (char '+' *> pure (+)) <++ (char '-' *> pure (-))
  mulOrDiv = (char '*' *> pure (*)) <++ (char '/' *> pure (/))

fexpression :: ReadP (Eval Function)
fexpression = foldl (liftA2 fapply)
  <$> (getf <$> name)
  <*> many (char '[' *> expression <* char ']')

declare, assign, loop, ask, stmt :: ReadP (Eval ())
declare = do
  f <- name <* string "is"
  optional $ string "function" *> string "of" *> munch1 isDigit *> char ':'
  as <- expression `sepBy1` char ',' <* char '.'
  return $ setf f as
assign = fmap sequence_ $
  string "assign" *> to `sepBy1` string "and" <* char '!'
  where
  to = flip setf <$> (fmap (:[]) expression) <*> (string "to" *> name)
loop = repf <$> (string "do" *> char '{' *> expression <* char '}') <*> assign
ask = do
  _ <- string "what" *> string "is"
  fs <- fexpression `sepBy1` string "and" <* char '?'
  return $ mapM_ (liftIO . print =<<) fs
stmt = foldl1 (<++) [declare, assign, loop, ask] <* skipSpaces <* eof

main :: IO ()
main = do
  inputs <- lines <$> getContents
  let program = sequence_
        [ e
        | i <- map toLower <$> inputs
        , not $ null i
        , let [(e, "")] = readP_to_S stmt i
        ]
  program `evalStateT` Map.empty
