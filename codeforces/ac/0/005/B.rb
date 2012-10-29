a = readlines.map(&:chop)
n = a.map(&:size).max
h = ['*' * n]
c = 0
puts (h + a + h).map{|_|
	if (n - _.size).odd?
		_ = c.odd? ? " #{_}" : "#{_} "
		c += 1
	end
	"*#{_.center(n)}*"
} * "\n"
__END__
#  	When  	Who  	Problem  	Lang  	Verdict  	Time  	Memory
256008 	Jan 21, 2011 10:26:06 AM 	watashi 	5B - Center Alignment 	Ruby 	Accepted 	360 ms 	10200 KB 
