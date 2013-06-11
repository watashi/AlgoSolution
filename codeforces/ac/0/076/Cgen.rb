n = 1024
m = 10
t = 0
s = Array.new(n){ [*'A'..'Z'][rand(m)] } * ''
d = Array.new(m){ 0 }
a = Array.new(m){ Array.new(m){ rand(10..99) } }

$> = open('C.in', 'w')
puts "#{n} #{m} #{t}"
puts s
puts d * ' '
puts a.map{|i| i * ' '} * "\n"

$> = open('C.ans', 'w')
x = s.chars.map{|i| i.ord - 'A'.ord}
(1 << m).times do |i|
  y = x.select{|j| i[j] == 0}
  z = y.each_cons(2).map{|i, j| a[i][j]}.inject(0, &:+)
  puts z
end
