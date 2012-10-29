n = gets.to_i
a = Array.new(n){gets.split.map &:to_i}
c = 0
n.times{|i|
    n.times{|j|
        x, y = 0, 0
        n.times{|k|
            x += a[i][k]
            y += a[k][j]
        }
        c += 1 if x < y
    }
}
p c
