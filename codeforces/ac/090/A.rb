r, g, b = gets.split.map{|_| _.to_i.succ / 2 * 3}
puts 30 + [r - 3, g - 2, b - 1].max
