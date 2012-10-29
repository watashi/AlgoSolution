n = gets.to_i
h = Hash.new{[]}
n.times{|i|
    c, s = gets.split.map(&:to_i)
    h[c] <<= [s, i + 1]
}

a = Array.new(n){[]}
h.each{|c, s|
    s.sort!.reverse!
    s.each_cons(2){|i, j|
        j[0] += i[0]
    }
    s.each_index{|i|
        a[i] << s
    }
}

n.times{|i|
    a[i].sort_by!{|_| -_[i][0]}
}
z = [0]
n.times{|i|
    [[0, 0, 1], [0, 1, 0], [0, 1, 1], [1, 1, 0]].each{|x, j, y|
        j += i
        b, c = a[i][x], a[j] && a[j][y]
        z = [z, [b[i][0] + c[j][0], i, x, j, y]].max if b && c && !b.equal?(c)
    }
}

u, i, x, j, y = z
p u
v = a[j][y][0..j].zip(a[i][x][0..i]).inject(&:concat).compact
p v.size
puts v.map{|_| _[1]} * ' '
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1338411 	Mar 10, 2012 9:33:19 PM 	watashi 	E - Zebra Tower 	Ruby 	Accepted 	2770 ms 	29800 KB
