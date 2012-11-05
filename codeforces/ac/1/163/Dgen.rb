require 'prime'

x = 106858629141264000
y = x.prime_division
p 1
p y.size
puts y.map{|_| _ * ' '} * "\n"
