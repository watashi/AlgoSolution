n, m = gets.split.map(&:to_i)
a = Array.new(n){[false] * n}
c = [0] * n
v = n.times.to_a
m.times do
	x, y = gets.split.map{|_| _.to_i - 1}
	a[x][y] = a[y][x] = true
	c[x] += 1
	c[y] += 1
end

ans = 0
loop do
	w = v.select{|i| c[i] == 1}
	break if w.empty?
	w.each do |i|
		next if c[i] != 1
		j = a[i].index(true)
		a[i][j] = a[j][i] = false
		c[i] -= 1
		c[j] -= 1
	end
	ans += 1
end
p ans

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
871407 	Nov 15, 2011 3:21:16 PM 	watashi 	129B - Students and Shoelaces 	Ruby 	Accepted 	130 ms 	3600 KB 
