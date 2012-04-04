n = gets.to_i
a = Array.new(n){gets.split.map(&:to_i)}
p a.count{|x, y|
    c = [0] * 9
    a.each{|i, j|
        c[(i <=> x) * 3 + (j <=> y) + 4] += 1
    }
    [1, 3, 5, 7].all?{|_| c[_] > 0}
}
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1408571 	Mar 25, 2012 4:25:29 PM 	watashi 	165A - Supercentral Point 	Ruby 	Accepted 	130 ms 	5500 KB
