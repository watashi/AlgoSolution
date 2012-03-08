a = [0]
b = []
(readlines.map(&:chomp) * '').scan(/<(ta|\/ta|td)/) do |_,|
	case _
	when 'ta' then a << 0
	when '/ta' then b << a.pop
	when 'td' then a[-1] += 1
	end
end
puts b.sort * ' '
__END__
WA4 <<map(&:chomp)>>
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
235165 	Dec 29, 2010 11:00:50 PM 	watashi 	B - bHTML Tables Analisys 	Ruby 	Accepted 	80 ms 	2984 KB
