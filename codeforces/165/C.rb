k = gets.to_i
s = gets.chop
a = [0]
b = []
s.size.times{|i|
    if s[i] == '1'
        a << a[-1] + 1
        b << i
    else
        a << a[-1]
    end
}
b += [s.size] * (k + 1)
c = 0
a.each_with_index{|i, j|
    c += b[i + k] - (k == 0 ? j : b[i + k - 1])
}
p c
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1408645 	Mar 25, 2012 4:52:50 PM 	watashi 	165C - Another Problem on Strings 	Ruby 	Accepted 	1860 ms 	30900 KB
