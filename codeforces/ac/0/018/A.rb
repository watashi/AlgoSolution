def dot(x0, y0, x1, y1, x2, y2)
	(x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0)
end

def right(x0, y0, x1, y1, x2, y2)
	[x0, y0] != [x1, y1] and [x0, y0] != [x2, y2] and [x1, y1] != [x2, y2] and
		dot(x0, y0, x1, y1, x2, y2) == 0 ||
		dot(x1, y1, x0, y0, x2, y2) == 0 ||
		dot(x2, y2, x0, y0, x1, y1) == 0
end

def gao(a)
	return "RIGHT" if right(*a)
	a.each_index do |i|
		a[i] += 1
		return "ALMOST" if right(*a)
		a[i] -= 2
		return "ALMOST" if right(*a)
		a[i] += 1
	end
	"NEITHER"
end

puts gao gets.split.map &:to_i

__END__
WA31: LINE#6
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213045 	Dec 10, 2010 1:48:03 PM 	watashi 	A - Triangle 	Ruby 	Accepted 	80 ms 	3004 KB
