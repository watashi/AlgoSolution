x, y, z = 0, 0, 0
gets.to_i.times do
	a, b, c = gets.split.map(&:to_i)
	x += a
	y += b
	z += c
end
puts [x, y, z] == [0, 0, 0] ? :YES : :NO
