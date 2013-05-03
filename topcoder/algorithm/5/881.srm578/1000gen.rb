n = 50
a = Array.new(n - 1){|i| [i + 1, rand(i + 1)]}
b = n.times.to_a.shuffle
x = a.map{|i, _| b[i]}
y = a.map{|_, i| b[i]}
p x
p y
