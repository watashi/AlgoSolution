x, y = gets.split.map(&:to_i)
z = []
while x > 0 || y > 0
    d = y % 3 - x % 3
    d += 3 if d < 0
    z << d
    x /= 3
    y /= 3
end
p (z.reverse * '').to_i(3)
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1127839 	Jan 31, 2012 9:59:24 AM 	watashi 	136B - Ternary Logic 	Ruby 	Accepted 	110 ms 	5500 KB
