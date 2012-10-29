n = gets.to_i
x = Array.new(n, -1)
dp = Array.new(n, 0)
(0 .. n - 1).each do |i|
	a, b = gets.split
	b = b.to_i
	dp[i] = dp[i - 1] if i > 0
	if a == 'win' then
		x[i] = b
	else
		(0 .. i - 1).each do |j|
			dp[i] = [dp[i], dp[j] + (1 << b)].max if x[j] == b
		end
	end
end
p dp[-1]

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213109 	Dec 10, 2010 4:15:39 PM 	watashi 	D - Seller Bob 	Ruby 	Accepted 	1810 ms 	3500 KB 

def read
	a, b = gets.split
	a == 'win' ? b.to_i : -1 - b.to_i
end

n, s, a = gets.to_i, 0, []
n.times{a << read}
a.reject{|i| i >= 0}.sort.each do |x|
	next unless t = a.index(x)
	next unless f = a[0 .. t].rindex(-1 - x)
	s += 1 << -1 - x
	a.slice!(f .. t)
end
p s

WA5: test data error?
