r = /[\w_]{1,16}/
puts gets =~ /^#{r}@(#{r}(\.#{r})*)(\/#{r})?$/ && $1.size <= 32 ? :YES : :NO
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
278915 	Feb 11, 2011 6:44:52 PM 	watashi 	21A - Jabber ID 	Ruby 	Accepted 	90 ms 	3000 KB 
