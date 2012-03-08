n = gets.to_i
a = Array.new(5){[false] * 5}
n.times do
	x, y = gets.split.map{|_| _.to_i - 1}
	a[x][y] = a[y][x] = true
end
5.times do |i|
	i.times do |j|
		j.times do |k|
			if (a[i][j] && a[j][k] && a[k][i]) || !(a[i][j] || a[j][k] || a[k][i])
				puts :WIN
				exit
			end
		end
	end
end
puts :FAIL

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
604703 	Aug 13, 2011 10:55:38 AM 	watashi 	94B - Friends 	Ruby 	Accepted 	90 ms 	3500 KB 
