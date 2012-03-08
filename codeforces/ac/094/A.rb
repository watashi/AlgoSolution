d = {}
e = gets
10.times{|i| d[gets.chomp] = i}
puts e.gsub(/.{10}/){d[$&]}

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
604623 	Aug 13, 2011 8:39:43 AM 	watashi 	94A - Restoring Password 	Ruby 	Accepted 	90 ms 	3500 KB
