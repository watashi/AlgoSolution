a = gets.split.map{|i| [i[0].ord - 97, i[1].ord - 49]}
b = Array.new(8){Array.new(8){false}}
c = Array.new(8){Array.new(8){false}}
a[0 .. 2].each{|x,y| b[x][y] = true}
a[0 .. 1].each do |x,y|
	x.pred.downto(0).each{|i| c[i][y] = true; break if b[i][y]}
	x.succ.upto(7).each{|i| c[i][y] = true; break if b[i][y]}
	y.pred.downto(0).each{|j| c[x][j] = true; break if b[x][j]}
	y.succ.upto(7).each{|j| c[x][j] = true; break if b[x][j]}
end
(a[2][0] - 1 .. a[2][0] + 1).each do |i|
	(a[2][1] - 1 .. a[2][1] + 1).each do |j|
		c[i][j] = true if (0 .. 7).include?(i) && (0 .. 7).include?(j)
	end
end
(a[3][0] - 1 .. a[3][0] + 1).each do |i|
	(a[3][1] - 1 .. a[3][1] + 1).each do |j|
		if (0 .. 7).include?(i) && (0 .. 7).include?(j) && !c[i][j] then
			puts :OTHER
			exit
		end
	end
end
puts :CHECKMATE

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
218570 	Dec 12, 2010 6:27:34 PM 	watashi 	B - Game of chess unfinished 	Ruby 	Accepted 	90 ms 	3012 KB 
