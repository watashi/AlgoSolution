h = Hash.new(0)
u = gets.chomp
gets.to_i.times do
	$_ = gets
	if /(\w+) posted on (\w+)'s wall/
		x, y, z = $1, $2, 15
	elsif /(\w+) commented on (\w+)'s post/
		x, y, z = $1, $2, 10
	elsif /(\w+) likes (\w+)'s post/
		x, y, z = $1, $2, 5
	else
		warn 555
	end
	if x == u
		h[y] += z
	elsif y == u
		h[x] += z
	else
		h[x] += 0
		h[y] += 0
	end
end
puts h.map{|k, v| [-v, k]}.sort.map{|a, b| b} * "\n"
