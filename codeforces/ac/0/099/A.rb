gets
if /(.*(.))\.(.)/
	puts $2 == '9' ? 'GOTO Vasilisa.' : $1.to_i + ($3 < '5' ? 0 : 1)
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
602712 	Aug 11, 2011 5:20:19 PM 	watashi 	99A - Help Far Away Kingdom 	Ruby 	Accepted 	110 ms 	3600 KB
