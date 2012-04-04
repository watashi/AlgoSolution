def f(n, a, b)
    if a > b
        f(n, b, a)
    else
        (b / n).floor + 1 - (a / n).ceil
    end
end

x, y, a, b, c, d = gets.split.map(&:to_r)
p [f(2 * x, a + b, c + d), f(2 * y, a - b, c - d)].max

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1155234 	Feb 7, 2012 12:45:21 PM 	watashi 	123B - Squares 	Ruby 	Accepted 	110 ms 	5500 KB
