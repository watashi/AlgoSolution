def inv(x)
	y = 0
	while x > 0
		y = y * 10 + x % 10
		x /= 10
	end
	return y
end

c = 0
1.upto(22) do |i|
	1.upto(111) do |j|
		if i * j == inv(i) * inv(j)
			c += 1
		end
	end
end
p c
