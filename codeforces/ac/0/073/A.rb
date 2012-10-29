x, y, z, k = gets.split.map(&:to_i)
x, y, z = [x, y, z].sort
x = [x - 1, k / 3].min
k -= x
y = [y - 1, k / 2].min
k -= y
z = [z - 1, k / 1].min
k -= z
p (x + 1) * (y + 1) * (z + 1)
