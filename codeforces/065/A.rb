a, b, c, d, e, f = gets.split.map(&:to_i)
puts (c == 0 && d > 0) ||
	(a == 0 && b > 0 && c > 0 && d > 0) ||
	(e == 0 && f > 0 && a > 0 && b > 0 && c > 0 && d > 0) ||
	a * c * e < b * d * f ? :Ron : :Hermione
