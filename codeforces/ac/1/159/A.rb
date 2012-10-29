n, d = gets.split.map(&:to_i)
h = Hash.new{[]}
s = {}
n.times{
    c = gets.split
    t = c.pop.to_i
    s[c.sort] = 0 if h[c.reverse].any?{|_| t - d <= _ && _ < t}
    h[c] <<= t
}
p s.size
puts s.keys.map{|_| _ * ' '} * "\n"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1338062 	Mar 10, 2012 8:02:10 PM 	watashi 	159A - Friends or Not 	Ruby 	Accepted 	130 ms 	5500 KB
