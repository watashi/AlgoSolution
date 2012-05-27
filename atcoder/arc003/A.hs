import Data.List (elemIndex)
import Data.Maybe

score = (flip elemIndex) "FDCBA"
gao s = (++"\n") $ show $ fromIntegral y / fromIntegral x where
    t = filter (isJust . score) s
    x = length t
    y = sum $ map (fromJust . score) t
main = do interact gao
