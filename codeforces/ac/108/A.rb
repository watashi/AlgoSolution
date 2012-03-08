if gets =~ /:/
	h = $`.to_i
	m = $'.to_i
	s = ''
	loop do
		m = m.succ % 60
		h = h.succ % 24 if m == 0
		s = '%02d:%02d' % [h, m]
		break if s == s.reverse
	end
	puts s
end

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#640012 	Aug 27, 2011 4:57:11 PM 	watashi 	108A - Palindromic Times 	Ruby 	Accepted 	90 ms 	3500 KB
