n, k = gets.split.map(&:to_i)
m = k / 2
a = Array.new(k){?0 * k}
gets.split.map(&:to_i).each do |w|
	d, x, y = 9e9
	0.upto(k - 1) do |i|
		0.upto(k - w) do |j|
			next if a[i][j, w] != ?0 * w
			t = w.times.map{|k| (i - m).abs + (j + k - m).abs}.inject(&:+)
			d, x, y = t, i, j if t < d
		end
	end
	if d == 9e9
		p -1
	else
		a[x][y, w] = ?1 * w
		puts "#{x + 1} #{y + 1} #{y + w}"
	end
end
