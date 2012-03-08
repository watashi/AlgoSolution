def no()
	puts "NO"
	exit
end

x = [[]]
y = [[]]
4.times do
	x1, y1, x2, y2 = gets.split.map{|i| i.to_i}
	if x1 == x2 && y1 == y2 then
		no()
	elsif x1 == x2 then
		x[0] <<= x1
		y <<= [y1, y2]
	elsif y1 == y2 then
		y[0] <<= y1
		x <<= [x1, x2]
	else
		no()
	end
end
x.map!{|i| i.sort}
y.map!{|i| i.sort}
no() unless x == Array.new(3, x[0])
no() unless y == Array.new(3, y[0])
puts "YES"

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#212096 	Dec 8, 2010 1:29:45 AM 	watashi 	C - Four Segments 	Ruby 	Accepted 	90 ms 	3004 KB 

