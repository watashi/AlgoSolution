require 'set'
n = gets.to_i
m = n * (n - 1) / 2
b = m.times.map{gets.split.map(&:to_i)[1..-1].to_set}
if n == 2
	a = [b[0].to_a[0..0], b[0].to_a[1..-1]]
else
	a = []
	1.upto(b.size - 1) do |i|
		unless (b[0] & b[i]).empty?
			a << (b[0] & b[i])
			break
		end
	end
	b.each do |c|
		unless (c & a[0]).empty?
			a << (c - a[0])
		end
	end
end
a.each do |c|
	puts "#{c.size} #{c.to_a * ' '}"
end

