def extgcd(a, b)
	if b == 0
		[a, 1, 0]
	else
		g, x, y = extgcd(b, a % b)
		[g, y, x - a / b * y]
	end
end

a, b, c = gets.split.map(&:to_i)
g, x, y = extgcd(a, b)

if c % g == 0
	c /= -g
	puts "#{x*c} #{y*c}"
else
	p -1
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
267879 	Jan 30, 2011 6:41:31 PM 	watashi 	7C - Line 	Ruby 	Accepted 	80 ms 	3000 KB 
