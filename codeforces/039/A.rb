a = gets.to_i
gets.scan(/([+-])?(?:(\d*)\*)?(a\+\+|\+\+a)/){$* << [(($1 || '+') + ($2 || '1')).to_i, $3]}
s = 0
$*.sort.each do |c, d|
	if d == 'a++'
		s += c * a
	else
		s += c * (a + 1)
	end
	a += 1
end
p s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
402429 	Apr 19, 2011 11:54:21 PM 	watashi 	39A - C*++ Calculations 	Ruby 	Accepted 	110 ms 	3400 KB
