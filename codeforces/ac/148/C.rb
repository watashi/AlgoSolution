n, a, b = gets.split.map(&:to_i)
c = [1]
if b == 0 && a > 0
    if a == n - 1
        p -1
        exit
    else
        c << 1
    end
end
b.times{c << c.inject(&:+) + 1}
a.times{c << c.max + 1}
c << 1 while c.size < n
puts c * ' '
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1144237 	Feb 2, 2012 11:32:40 PM 	watashi 	148C - Terse princess 	Ruby 	Accepted 	110 ms 	5500 KB
