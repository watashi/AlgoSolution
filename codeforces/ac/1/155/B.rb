n = gets.to_i
a = Array.new(n){gets.split.map(&:to_i).reverse}.sort.reverse
b, c = 1, 0
a.each do |x, y|
    break if b == 0
    b += x - 1
    c += y
end
p c
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1235544 	Feb 26, 2012 2:02:22 AM 	watashi 	155B - Combination 	Ruby 	Accepted 	110 ms 	5500 KB
