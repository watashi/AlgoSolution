n = gets.to_i
r = []
n.times do
	w, s = gets.split
	r << [w, s.to_i]
end

a = Hash.new(0)
r.each do |w,s|
	a[w] += s
end
m = a.max{|x,y| x[1] <=> y[1] }[1]

b = Hash.new(0)
r.each do |w,s|
	b[w] += s
	if a[w] == m && b[w] >= m then
		puts w
		exit
	end
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
255043 	Jan 19, 2011 4:02:17 PM 	watashi 	2A - Winner 	Ruby 	Accepted 	80 ms 	3000 KB 
