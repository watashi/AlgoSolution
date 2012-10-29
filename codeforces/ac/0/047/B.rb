x = {'A' => 0, 'B' => 0, 'C' => 0}
s = '___'
3.times do
	a, o, b = gets.scan(/./)
	o == '>' ? x[a] += 1 : x[b] += 1
end
x.each do |k, v|
	s[v] = k
end
s = 'Impossible' if s =~ /_/
puts s

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213198 	Dec 10, 2010 8:12:13 PM 	watashi 	B - Coins 	Ruby 	Accepted 	80 ms 	3000 KB
