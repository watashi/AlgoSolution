r = ->{gets.split.map &:to_i}
n, m = r[]
a = r[]
p a.count{|_| _ >= [1, a[m - 1]].max}
