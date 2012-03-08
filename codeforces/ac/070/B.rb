n = gets.to_i
s = gets.scan(/.*?[\.?!]/).map{|_| _.strip.size}
x, y = 0, 0
s.each do |_|
	if _ > n
		puts :Impossible
		exit
	elsif x == 0
		x = _
	else
		x += 1 + _
		if x > n
			x = _
			y += 1
		end
	end
end
if x > 0
	y += 1
end
p y
