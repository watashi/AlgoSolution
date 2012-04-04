gets
a, b = 2.times.map{gets.split.map(&:to_i)}
c = a.each_with_index.map{|j, i| [b.count{|k| k % j == 0}, i + 1]}
c.reject!{|j, i| j != c.min[0]}
p c.size
puts c.map(&:last) * ' '
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
402375 	Apr 19, 2011 11:38:57 PM 	watashi 	39F - Pacifist frogs 	Ruby 	Accepted 	90 ms 	3400 KB
