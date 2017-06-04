import Control.Applicative hiding (many)
import Control.Monad
import Control.Monad.Trans.State.Strict
import Data.Char
import Data.Map.Strict (Map)
import qualified Data.Map.Strict as Map
import Text.ParserCombinators.ReadP hiding (char, string, munch1)
import qualified Text.ParserCombinators.ReadP as ReadP

type Eval a = State (Map String Int) a

getv :: String -> Eval Int
getv v = gets (Map.! v)

setv :: String -> Eval Int -> Eval ()
setv v n = modify . Map.insert v =<< n

char :: Char -> ReadP Char
char c = skipSpaces *> ReadP.char c

string :: String -> ReadP String
string s = skipSpaces *> ReadP.string s

munch1 :: (Char -> Bool) -> ReadP String
munch1 p = skipSpaces *> ReadP.munch1 p

var :: ReadP String
var = munch1 isLower

num :: ReadP Int
num = read <$> munch1 isDigit

aexp :: ReadP (Eval Int)
aexp = expression
  where
  expression = foldl app <$> term <*> many ((,) <$> addOrSub <*> term)
  term = foldl app <$> factor <*> many ((,) <$> mulOrDiv <*> factor)
  factor = foldl1 (<++)
    [ char '(' *> expression <* char ')'
    , return <$> num
    , getv <$> var
    ]
  app i (op, j) = op <$> i <*> j
  addOrSub = (char '+' *> pure (+)) <++ (char '-' *> pure (-))
  mulOrDiv = (char '*' *> pure (*)) <++ (char '/' *> pure quot)

bexp :: ReadP (Eval Bool)
bexp = dnf
  where
  dnf = fmap and . sequence <$> clause `sepBy1` string "or"
  clause = fmap and . sequence <$> value `sepBy1` string "and"
  value = foldl1 (<++)
    [ char '(' *> dnf <* char ')'
    , string "true" *> pure (return True)
    , string "fasle" *> pure (return False)
    , app <$> aexp <*> gtOrLt <*> aexp
    ]
  app i op j = op <$> i <*> j
  gtOrLt = (char '>' *> pure (>)) <++ (char '<' *> pure (<))

stmts :: ReadP (Eval ())
stmts = sequence_ <$> stmt `sepBy` char ';'
  where
  block = char '{' *> stmts <* char '}'
  stmt = foldl1 (<++)
    [ setv <$> var <*> (string ":=" *> aexp)
    , ifThenElse
        <$> (string "if" *> bexp)
        <*> (string "then" *> block)
        <*> (string "else" *> block)
    , whileDo
        <$> (string "while" *> bexp)
        <*> (string "do" *> block)
    ]
  ifThenElse i t e = do
    b <- i
    if b then t else e
  whileDo w d = do
    b <- w
    when b $ d >> whileDo w d

program :: ReadP (Eval ())
program = stmts <* skipSpaces <* eof

main :: IO ()
main = do
  [(eval, "")] <- readP_to_S program <$> getContents
  let table = eval `execState` Map.empty
  putStr $ unlines [k ++ " " ++ show v | (k, v) <- Map.assocs table]
