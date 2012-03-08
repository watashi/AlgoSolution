readlines.map(&:chomp).permutation do |a,b,c,d,e,f|
	x = a.size - 1
	y = b.size - 1
	m = c.size
	n = d.size
	next if x + e.size != m ||
			y + f.size != n ||
			a[0] != b[0] ||
			a[-1] != d[0] ||
			b[-1] != c[0] ||
			c[x] != d[y] ||
			c[-1] != f[0] ||
			d[-1] != e[0] ||
			e[-1] != f[-1]
	o = [*1..m].map{'.' * n}
	(0 .. x).each{|i| o[i][0] = a[i]}
	o[0][0 .. y] = b
	(0 .. m - 1).each{|i| o[i][y] = c[i]}
	o[x] = d
	(x .. m - 1).each{|i| o[i][-1] = e[i - x]}
	o[-1][y .. -1] = f
	$* << o * "\n"
end
puts $*.empty? ? :Impossible : $*.min

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213211 	Dec 10, 2010 8:58:55 PM 	watashi 	C - Crossword 	Ruby 	Accepted 	80 ms 	3000 KB 
