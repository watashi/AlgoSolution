s = 0
n, m = gets.split.map(&:to_i)
m.times{$*<<gets.split.map(&:to_i)}
$*.sort{|a, b| b[1] <=> a[1]}.each do |a, b|
	t = [n, a].min
	n -= t
	s += b * t
end
p s

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
212857 	Dec 9, 2010 9:59:45 PM 	watashi 	B - Burglar and Matches 	Ruby 	Accepted 	80 ms 	2992 KB
