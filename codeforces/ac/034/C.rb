a = gets.split(',').map(&:to_i).sort
b = []
s = t = a[0]
a.each do |i|
	if i <= t + 1 then
		t = i
	else
		b << [s, t]
		s = t = i
	end
end
b << [s, t]
puts b.map{|a, b| a == b ? a : "#{a}-#{b}"} * ','
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230173 	Dec 27, 2010 11:15:33 AM 	watashi 	C - Page Numbers 	Ruby 	Accepted 	80 ms 	5068 KB 
