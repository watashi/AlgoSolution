def gao(i, j, m, n)
	m /= n
	m > 0 && ($a[i / m][j / m] == '*' || gao(i % m, j % m, m, n))
end

I = open('input.txt')
O = open('output.txt', 'w')
n, k = I.gets.split.map(&:to_i)
$a = n.times.map{I.gets}
m = n ** k
O.puts m.times.map{|i| m.times.map{|j| gao(i, j, m, n) ? '*' : '.'} * ''} * "\n"

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235999 	Jan 2, 2011 7:12:56 PM 	watashi 	B - Fractal 	Ruby 	Accepted 	380 ms 	3040 KB
