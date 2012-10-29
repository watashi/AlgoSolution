n = gets.to_i
m = 0
loop do
	break if ('%b' % m).to_i > n
	m += 1
end
p m - 1

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#209209 	Dec 6, 2010 6:30:32 PM 	watashi 	C - Hexadecimal's Numbers 	Ruby 	Accepted 	80 ms 	2984 KB 
