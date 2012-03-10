I = ->{gets.split.map(&:to_i)}
n, m = I[]
def r(n)
    h = {}
    n.times{
        x, y = I[]
        h[y] = h[y] || Hash.new(0)
        h[y][x] += 1
    }
    h
end
a, b, u, v = r(n), r(m), 0, 0
a.merge(b){|_, c, d|
    u += [c, d].map{|_| _.values.inject(&:+)}.min
    c.merge(d){|_, e, f|
        v += [e, f].min
    }
}
puts "#{u} #{v}"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1338133 	Mar 10, 2012 8:21:09 PM 	watashi 	B - Matchmaker 	Ruby 	Accepted 	1880 ms 	16800 KB
