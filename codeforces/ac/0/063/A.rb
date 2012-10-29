n = gets.to_i
r, w, m, c = [], [], [], []
n.times do
	a, b = gets.split
	case b
		when 'rat'
			r << a
		when 'child'
			w << a
		when 'woman'
			w << a
		when 'man'
			m << a
		when 'captain'
			c << a
	end
end
puts (r + w + m + c) * "\n"
