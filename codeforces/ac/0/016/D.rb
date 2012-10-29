D = 1440
n = gets.to_i
n.times{$* << ($1.to_i % 12 * 60 + $2.to_i + ($3 == 'a' ? 0 : 720)) % D if gets =~ /^\[(\d+):(\d+) ([ap])/}
$*.each_index do |i|
	$*[i] += D while i >= 1 && $*[i] < $*[i - 1]
	$*[i] += D while i >= 10 && $*[i] == $*[i - 10]
end
p $*[-1] / D + 1

__END__
WA14: $1.to_i % 12
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213039 	Dec 10, 2010 1:16:56 PM 	watashi 	D - Logging 	Ruby 	Accepted 	90 ms 	3008 KB
