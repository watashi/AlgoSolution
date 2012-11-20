import Data.Array.Unboxed
import Data.Maybe
import qualified Data.Array as A
import qualified Data.ByteString.Char8 as C

type U = UArray Int Int

pal n s = [(l, r, go l r) | l <- [1 .. n], r <- [l, l + 1]]
	where
		a = A.listArray (1, n) $ C.unpack s
		go l r = if 1 <= l && r <= n && a!l == a!r then go (l - 1) (r + 1) + 1 else 0

solve s q = go q
	where
		go [] = []
		go (l:r:t) = ' ': show (a A.! l ! r) ++ go t
		n = C.length s
		p = pal n s
		a = listArray (1,n) $ map gao [1 .. n]
		gao s = listArray (s,n) $ scanl1 (+) $ scanl1 (+) $ elems d :: U
			where
				d = accumArray (+) 0 (s,n+1) $ concat [[(r, 1), (r + m', -1)] |
					(l,r,m) <- p,
					let m' = min m $ l - s + 1,
					m' > 0] :: U

main = do
	s <- C.getLine
	C.getLine
	q <- fmap (map (fst . fromJust . C.readInt) . C.words) C.getContents
	putStr $ solve s q
