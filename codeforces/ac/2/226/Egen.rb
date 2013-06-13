n = 10
v = n.times.to_a.shuffle
e = Array.new(n){|i| [i, i == 0 ? -1 : rand(i)]}
e = e.map{|i, j| [v[i], j == -1 ? j : v[j]]}.sort

puts n
puts e.map{|_, i| i + 1} * ' '

m = 10
v = v.shuffle
puts m
m.times do |i|
  if rand < 0.4
    puts "1 #{v.pop + 1}"
  else
    a = rand(1 .. n)
    b = rand(1 .. n)
    redo if a == b
    puts "2 #{a} #{b} #{rand(1 .. 5)} #{rand(i + 1)}"
  end
end
