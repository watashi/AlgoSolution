n, x, y = gets.split.map &:to_i
n /= 2
puts [x, y].all?{|_| _ == n || _ == n + 1} ? :NO : :YES
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
667558 	Sep 4, 2011 4:01:33 PM 	watashi 	112B - Petya and Square 	Ruby 	Accepted 	90 ms 	3500 KB 
