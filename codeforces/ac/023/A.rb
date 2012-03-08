s = gets.chomp
n = s.size
0.upto(n) do |i|
	next if 0.upto(i).map{|j| s[j, n - i]}.sort.uniq.size > i
	p n - i
	break
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
300781 	Feb 23, 2011 4:42:59 PM 	watashi 	23A - Youre Given a String... 	Ruby 	Accepted 	90 ms 	4300 KB 
