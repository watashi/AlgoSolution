n, k, t = gets.split.map(&:to_i)
s = n * k * t / 100
a = []
n.times do
	a << [s, k].min
	s -= a[-1]
end
puts a * ' '
