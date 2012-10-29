def read
	a, b = gets.split
	a == 'win' ? b.to_i : -1 - b.to_i
end

n = gets.to_i
n.times{$* << read}
ans = 0
$*.reject{|i| i >= 0}.sort.each do |x|
	next unless b = $*.index(x)
	next unless a = $*[0 .. b].rindex(-1 - x)
	next unless $*[a..b].all?	# WA5
	ans += 2 ** (-1 - x)
	$*[a..b] = [nil]
end
p ans
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
234868 	Dec 29, 2010 2:10:31 PM 	watashi 	D - Seller Bob 	Ruby 	Accepted 	530 ms 	8928 KB
