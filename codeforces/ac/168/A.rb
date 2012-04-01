n, x, y = gets.split.map(&:to_i)
p [(n * y + 99) / 100 - x, 0].max
