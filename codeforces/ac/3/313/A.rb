x = gets.chomp
y = x.clone
y[-1] = ''
z = x.clone
z[-2] = ''
p [x, y, z].map(&:to_i).max
