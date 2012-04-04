n, m, k = gets.split.map(&:to_i)
if n.even?
	b = 0
else
	a = gets.split.map(&:to_i)
	b = m / ((n + 1) / 2) * k
	a.each_with_index do |j, i|
		b = [b, j].min if i.even?
	end
end
puts b
