$b = 4096.times.to_a.map{|i| i.to_s(2).count('1')}

def bits(x)
	$b[x & 4095] + $b[(x >> 12) & 4095] + $b[x >> 24]
end

n, m = gets.split.map(&:to_i)
a = []
m.times do |t|
	s, c = gets.split
	s = s.to_i(2)
	c = c.to_i
	if t.zero? then
		[*0..n-1].combination(c).each do |i|
			a << s
			i.each{|j| a[-1] ^= 1 << j}
		end
	else
		a.reject!{|i| bits(i ^ s) != c}
	end
end
p a.size

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
213235 	Dec 10, 2010 10:30:24 PM 	watashi 	D - Safe 	Ruby 	Accepted 	4140 ms 	20448 KB 

