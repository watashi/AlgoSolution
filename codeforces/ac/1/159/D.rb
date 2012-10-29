s = gets.chop
n = s.size
b = [0] * n
e = [0] * n
n.times{|i|
    2.times{|j|
        l, r = i, i + j
        while 0 <= l && s[l] == s[r]
            b[l] += 1
            e[r] += 1
            l -= 1
            r += 1
        end
    }
}
s, t = 0, 0
n.times{|i|
    s += t * b[i]
    t += e[i]
}
p s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1338455 	Mar 10, 2012 9:56:56 PM 	watashi 	D - Palindrome pairs 	Ruby 	Accepted 	1720 ms 	5500 KB
