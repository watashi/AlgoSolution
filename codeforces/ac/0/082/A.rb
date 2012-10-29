n = gets.to_i - 1
m = 1
loop do
	if n < 5 * m
		puts %w(Sheldon Leonard Penny Rajesh Howard)[n / m]
		break
	else
		n -= 5 * m
		m *= 2
	end
end
