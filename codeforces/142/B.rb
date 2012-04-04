n, m = gets.split.map(&:to_i).sort
p [m, m / 4 * 4 + [0, 2, 4, 4][m % 4], (n * m + 1) / 2][[n - 1, 2].min]
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1155122 	Feb 7, 2012 12:09:58 PM 	watashi 	142B - Help General 	Ruby 	Accepted 	110 ms 	5500 KB
