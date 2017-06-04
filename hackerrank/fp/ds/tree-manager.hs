{-# LANGUAGE OverloadedStrings #-}

import Control.Arrow
import Control.Monad.IO.Class
import Control.Monad.Trans.State.Strict
import Data.Tree
import qualified Data.ByteString.Char8 as C

data Context a = Context
  { parentLabel :: a 
  , leftSiblings :: Forest a
  , rightSiblings :: Forest a
  }
type TreeM = StateT ([Context Int], Tree Int) IO ()

changeLabel, visitChild, insertLeft, insertRight, insertChild :: Int -> TreeM
printLabel, visitLeft, visitRight, visitParent, delete :: TreeM
changeLabel x = modify $ second $ \t -> t{rootLabel = x}
printLabel = liftIO . print =<< gets (rootLabel . snd)
visitLeft = modify $ \(Context p (t': l) r: cs, t) -> (Context p l (t: r): cs, t')
visitRight = modify $ \(Context p l (t': r): cs, t) -> (Context p (t: l) r: cs, t')
visitParent = modify $ \(Context p l r: cs, t) -> (cs, Node p $ reverse l ++ (t: r))
visitChild n = modify $ \(cs, Node x y) ->
  let (l, t: r) = splitAt (n-1) y in (Context x (reverse l) r: cs, t)
insertLeft x = modify $ first $ \(c:cs) ->
  c{ leftSiblings = Node x []: leftSiblings c }: cs
insertRight x = modify $ first $ \(c:cs) ->
  c{ rightSiblings = Node x []: rightSiblings c }: cs
insertChild x = modify $ second $ \t ->
  t{ subForest = Node x []: subForest t }
delete = modify $ \(Context p l r: cs, _) ->
  (cs, Node p $ reverse l ++ r)

parse :: C.ByteString -> TreeM
parse cmd = case C.words cmd of
  ["change", x] -> changeLabel $ readInt x
  ["print"] -> printLabel
  ["visit", "left"] -> visitLeft
  ["visit", "right"] -> visitRight
  ["visit", "parent"] -> visitParent
  ["visit", "child", n] -> visitChild $ readInt n
  ["insert", "left", x] -> insertLeft $ readInt x
  ["insert", "right", x] -> insertRight $ readInt x
  ["insert", "child", x] -> insertChild $ readInt x
  ["delete"] -> delete
  _ -> error $ C.unpack cmd
  where
  readInt s = let Just (i, _) = C.readInt s in i

main :: IO ()
main = do
  (_:cmds) <- fmap C.lines C.getContents
  mapM_ parse cmds `evalStateT` ([], Node 0 [])