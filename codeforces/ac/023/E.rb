def gao(v, p)
	$e[v].delete(p)
	n, x, y, z = $e[v].size, 1, 1, 1
	dp = [1] + [0] * n
	$e[v].each do |w|
		a, b, c = gao(w, v)
		x *= a
		y = [y, Rational(b, a)].max
		z *= a
		n.downto(1) do |i|
			dp[i] = [dp[i - 1] * c, dp[i] * a].max
		end
		dp[0] *= a
	end
	x, y = (x * y).to_i, 0
	0.upto(n) do |i|
		x = [x, dp[i] * (i + 1)].max
		y = [y, dp[i] * (i + 2)].max
	end
	return x, y, z
end

n = gets.to_i
$e = Array.new(n){[]}
(n - 1).times do
	a, b = gets.split.map{|_| _.to_i - 1}
	$e[a] << b
	$e[b] << a
end
p gao(0, -1)[0]

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
301740 	Feb 24, 2011 8:17:16 PM 	watashi 	23E - Tree 	Ruby 	Accepted 	810 ms 	4200 KB 

很容易推出，最优的情况一定是把树剖分成若干个星形
PS：我的做法似乎和许多人不一样

