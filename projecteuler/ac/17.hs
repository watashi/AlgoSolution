a1 = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
a2 = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
a3 = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
a4 = "hundredand"

ten = length (concat a1)
twenty = ten + length (concat a2)
hundred = twenty + sum [length x * 10 + ten | x <- a3]
thousand = hundred + sum [length (x ++ a4) * 100 + hundred - length "and" | x <- tail a1]

main = do
	putStrLn $ show $ thousand + length "onethousand"
