n = gets.to_i
h = Hash.new(0)
gets.split.map(&:to_i).each_with_index do |i, j|
	k = i - [j, n - 1 - j].min
	h[k] += 1 if k > 0
end
p n - h.max{|a, b| a[1] <=> b[1]}[1]
__END__
271600 	Jan 31, 2011 9:25:31 PM 	watashi 	58C - Trees 	Ruby 	Accepted 	560 ms 	9400 KB 
