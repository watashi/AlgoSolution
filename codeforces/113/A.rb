$_ = gets.chomp + ' '
[%w(lios etr initis), %w(liala etra inites)].each do |r|
	r.map!{|_| "\\S*#{_}\\s+"}
	r << "(#{r[0]})*(#{r[1]})(#{r[2]})*";
	if /^(#{r.join('|')})$/
		puts :YES
		exit
	end
end
puts :NO
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
750473 	Oct 8, 2011 1:12:45 PM 	watashi 	113A - Grammar Lessons 	Ruby 	Accepted 	110 ms 	3900 KB
