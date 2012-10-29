n = gets.to_i
m = gets.to_i
l = -1
while m % n == 0
	m /= n
	l += 1
end
if m == 1
	puts :YES
	p l
else
	puts :NO
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
# 	686248 	Sep 9, 2011 6:00:43 PM 	watashi 	114A - Cifera 	Ruby 	Accepted 	90 ms 	3500 KB 
