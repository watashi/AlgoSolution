require 'date'
a = Date::MONTHNAMES[1..-1]
b = gets.chomp
c = gets.to_i
puts a[(a.index(b) + c) % 12]
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
413305 	Apr 28, 2011 1:10:20 AM 	watashi 	45A - Codecraft III 	Ruby 	Accepted 	140 ms 	4800 KB
