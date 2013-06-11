$a = [
	[],
	[0, 0, 0, 0, 0, 0],
	[0, 1, 3, 6, 0, 0],
	[0, 1, 2, 3, 5, 6]]

def gao(m, n)
	return m > 5 ? 0 : $a[n][m] if n < 4
	s = n / 2
	return 1 if m <= s
	s += (n - 1) / 2
	return 2 if m <= s
	s += n / 2 - 1
	return 3 if m <= s
	s += (n - 1) / 2
	return 4 if m <= s
	t = n / 2 - 1
	return t <= 0 ? 0 : 4 + (m - s + t - 1) / t
end

m, n = gets.split.map(&:to_i)
p gao(m, n) * 2 - 1

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
413397 	Apr 28, 2011 2:47:48 AM 	watashi 	45F - Goats and Wolves 	Ruby 	Accepted 	90 ms 	3800 KB 
