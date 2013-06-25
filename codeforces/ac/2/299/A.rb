gets
a = gets.split.map(&:to_i)
b = a.min
p a.map{|i| i % b}.max == 0 ? b : -1
