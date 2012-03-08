n = gets.to_i
a = []
(2 ** (n - 1) .. 2 ** n - 1).each do |i|
	s = i.to_s(2)
	s = [s, s.reverse, s.tr('01', '10'), s.tr('01', '10').reverse].min
	a << s
end
a = a.sort.uniq
p a
p a.size
