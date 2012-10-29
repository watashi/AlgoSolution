gets
a = gets.split.map(&:to_i).sort.uniq
1.upto(a.size - 1) do |i|
	if a[i] < 2 * a[i - 1]
		puts :YES
		exit
	end
end
puts :NO
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
640023 	Aug 27, 2011 5:02:37 PM 	watashi 	108B - Datatypes 	Ruby 	Accepted 	390 ms 	13700 KB
