n = gets.to_i
p = n.times.map{gets.split.map{|_| _.to_i * 2}}
q = {}
p.each{|_| q[_] = 1}
s = 0
p.each{|a|
    p.each{|b|
        break if a == b
        c = a.zip(b).map{|i, j| (i + j) / 2}
        s += 1 if q[c]
    }
}
p s
__END__
Time limit exceeded on test 7
