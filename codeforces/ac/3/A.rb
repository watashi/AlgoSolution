_, a, *q = readlines.map{|i| i.split.map(&:to_i)}
n = 2 * [a.count(1), a.count(-1)].min
puts q.map{|i, j|
  j -= i
  j.odd? && j < n ? 1 : 0
}
