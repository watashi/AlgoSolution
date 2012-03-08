def gao()
	s = $a.slice!(/\w*/)
	$c += $*.count(s)
	$* << s
	if $a.slice!(0) == ':'
		gao()
		gao() while $a.slice!(0) == ','
	end
	$*.pop
end

$a, $c = gets, 0
gao()
p $c

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
267491 	Jan 29, 2011 10:02:12 PM 	watashi 	56C - Corporation Mail 	Ruby 	Accepted 	80 ms 	3100 KB 
