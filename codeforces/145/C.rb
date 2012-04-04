M = 1000000007

def gcd(a, b)
    if b == 0
        [a, 1, 0]
    else
        g, x, y = gcd(b, a % b)
        [g, y, x - a / b * y]
    end
end

def inv(x, p)
    gcd(x, p)[1] % p
end

n, m = gets.split.map(&:to_i)
a = Hash.new(0)
b = 0
gets.split.each do |_|
    if _ =~ /[^47]/
        b += 1
    else
        a[_] += 1
    end
end

r = a.size
c = [1] + [0] * r
a.each do |k, v|
    r.downto(1) do |i|
        c[i] = (c[i] + c[i - 1] * v) % M
    end
end

s = 0
t = 1
0.upto([m, b].min) do |i|
    s += t * c[m - i] if m - i <= r
    t = t * (b - i) * inv(i + 1, M) % M
end
p s % M

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1152096 	Feb 6, 2012 5:39:04 AM 	watashi 	145C - Lucky Subsequence 	Ruby 	Accepted 	1310 ms 	13600 KB
