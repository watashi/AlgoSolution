y = 0
gets.to_i.times do
	x, m = gets.split.map(&:to_i);
	l, r = x, x + m
	while l < r && l % 4 != 0
		y ^= l
		l += 1
	end
	while l < r && r % 4 != 0
		r -= 1
		y ^= r
	end
end
puts y == 0 ? :bolik : :tolik
