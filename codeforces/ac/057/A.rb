def toi(n, x, y)
	if x == 0
		return y
	elsif y == n
		return n + x
	elsif x == n
		return n + n + (n - y)
	else
		return n + n + n + (n - x)
	end
end

n, x1, y1, x2, y2 = gets.split.map(&:to_i)
z1 = toi(n, x1, y1)
z2 = toi(n, x2, y2)
m = 4 * n
d = (z2 - z1 + m) % m
p [d, m - d].min
