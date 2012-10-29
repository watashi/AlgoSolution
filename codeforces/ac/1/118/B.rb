n = gets.to_i
a = Array.new(2 * n + 1){Array.new(2 * n + 1){' '}}
(-n .. n).each do |i|
	k = n - i.abs
	(-k .. k).each do |j|
		a[i + n][j + n] = (k - j.abs).to_s
	end
end
puts a.map{|_| (_ * ' ').rstrip} * "\n"
