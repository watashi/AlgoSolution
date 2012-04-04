n, m = gets.split.map(&:to_i)
p Array.new(m).zip(*(n.times.map{gets.chars.to_a})).map{|_| _.uniq.size - 1}.inject(&:*) % 1000000007
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1292097 	Mar 5, 2012 10:55:07 PM 	watashi 	152C - Pocket Book 	Ruby 	Accepted 	130 ms 	5500 KB
