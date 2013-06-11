n, s, c = gets.split.map(&:to_i)
d = gets =~ /tail/ ? 1 : -1
gets.scan(/[01]/).each_with_index do |w, i|
	s = c if w == ?1
	d = 1 if c == 1
	d = -1 if c == n
	c += d
	s += d if s == c
	unless (1 .. n).include? s
		puts "Controller #{i + 1}"
		exit
	end
end
puts :Stowaway
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
395992 	Apr 19, 2011 12:03:59 AM 	watashi 	74B - Train 	Ruby 	Accepted 	80 ms 	3800 KB 
