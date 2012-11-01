MAX = 10 ** 9

n = 1000
puts "#{n} 123456789"
r = Array.new(n){ rand(1 .. MAX) }
a = Array.new(n){ rand(1 .. MAX) }
puts r * ' '
puts a * ' '

m = 10000
puts m
m.times do
  puts "#{rand(1 .. n)} #{rand(1 .. n)}"
end
