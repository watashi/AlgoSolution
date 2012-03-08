NOTE = %w(C C# D D# E F F# G G# A B H)
a = gets.split
puts %w(strange minor major)[a.permutation.map do |i|
	i = i.map{|j| NOTE.index(j)}
	if i[1] == (i[0] + 4) % 12 && i[2] == (i[1] + 3) % 12
		2
	elsif i[1] == (i[0] + 3) % 12 && i[2] == (i[1] + 4) % 12
		1
	else
		0
	end
end.max]
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
509292 	Jun 24, 2011 4:29:28 AM 	watashi 	88A - Chord 	Ruby 	Accepted 	90 ms 	3500 KB 
