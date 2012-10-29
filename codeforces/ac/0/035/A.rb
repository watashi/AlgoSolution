I=open('input.txt')
O=open('output.txt','w')
n=I.gets.to_i
3.times do
	a, b = I.gets.split.map &:to_i
	n = n == a ? b : n == b ? a : n
end
O.puts n
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
230238 	Dec 27, 2010 7:19:26 PM 	watashi 	A - Shell Game 	Ruby 	Accepted 	80 ms 	2996 KB
