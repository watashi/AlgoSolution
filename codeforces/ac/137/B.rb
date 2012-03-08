n = gets.to_i
p n - gets.split.map(&:to_i).grep(1..n).uniq.size
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1130019 	Feb 1, 2012 12:23:42 PM 	watashi 	137B - Permutation 	Ruby 	Accepted 	130 ms 	5600 KB
