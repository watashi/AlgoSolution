n = gets.to_i
p = [-9e9]
n.times.map{gets.split.map(&:to_i).sort.reverse}.sort.each do |a,b|
	next if b <= p[-1]
	p << a
end
p p.size - 1
puts p[1..-1] * ' '

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219405 	Dec 15, 2010 4:10:27 PM 	watashi 	D - Segments 	Ruby 	Accepted 	90 ms 	2992 KB 
