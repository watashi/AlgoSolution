n = gets.to_i
gets

a = Array.new(n) {
  gets.split.map{|x| x.to_i - 1}
}

b = []
n.times {|i|
  a[i].each_index {|j|
    b << [i, j]
  }
}

c = []
50.times {
  n.times {|i|
  a[i].each_index {|j|
    t = a[i][j]
    next if b[t] == [i, j]
    x, y = *b[t]
    a[i][j], a[x][y] = a[x][y], a[i][j]
    c << [i, j, x, y].map(&:succ)
  }
}
}
p c.size
puts c.map{|i| i * ' '}
