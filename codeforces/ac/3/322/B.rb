a = gets.split.map(&:to_i)
p (a + [2]).min.succ.times.map{|i|
  a.map{|j| (j - i) / 3}.inject(i, &:+)
}.max
