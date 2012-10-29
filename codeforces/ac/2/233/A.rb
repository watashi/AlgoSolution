n = gets.to_i
puts n.odd? ? -1 : [*1..n].each_slice(2).map(&:reverse)
