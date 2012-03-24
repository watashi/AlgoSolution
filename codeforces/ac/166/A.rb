I = ->{gets.split.map(&:to_i)}
n, m = I[]
a = Array.new(n){I[]}.sort_by{|i, j| -i * 1000 + j}
p a.count(a[m - 1])
