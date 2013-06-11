n, m = gets.split.map(&:to_i)
if [n, m] == [1, 1]
	a = [[1]]
elsif [n, m] == [1, 4]
	a = [[2, 4, 1, 3]]
elsif [n, m] == [4, 1]
	a = [[2], [4], [1], [3]]
elsif n * m <= 4
	a = [[-1]]
elsif n == 1
	a = [[*1 .. m].partition{|_| _.odd?}.flatten]
elsif m == 1
	a = [*1 .. n].partition{|_| _.odd?}.flatten.map{|_| [_]}
else
	a = Array.new(n){Array.new(m)}
	k = 1
	n.times do |i|
		m.times do |j|
			until a[i][j]
				a[i][j] = k
				k += 1
				i = (i + 1) % n
				j = (j + 1) % m
			end
		end
	end
end
puts a.map{|_| _ * ' '} * "\n"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
413381 	Apr 28, 2011 2:33:41 AM 	watashi 	45J - Planting Trees 	Ruby 	Accepted 	90 ms 	4200 KB
