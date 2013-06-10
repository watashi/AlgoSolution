import Data.Time.Calendar
import Data.Time.Calendar.WeekDate

main = putStrLn $ show $ length $ filter (==7) $
	[(\(_, _, w) -> w) $ toWeekDate $ fromGregorian y m 1 | y <- [1901 .. 2000], m <- [1 .. 12]]

