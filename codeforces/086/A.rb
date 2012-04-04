def reflection(x)
	n = x.to_s.size
	return 10 ** n - 1 - x
end

l, r = gets.split.map(&:to_i)
n = r.to_s.size
a = [l, r]
1.upto(n) do
	m = 10 ** n
	a << (m / 2 - 1)
	a << (m / 2)
	a << m / 10
end
puts a.select{|_| (l..r).include?(_)}.map{|_| _ * reflection(_)}.max
