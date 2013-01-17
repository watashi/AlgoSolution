n = $*[0].to_i || 100000
v = [*1..n].shuffle
e = []

n.times do |i|
  e << [v[i], v[(i + 1) % n]].shuffle
  e << [v[i], v[(i + 2) % n]].shuffle
end

puts n
puts e.map{|i| i * ' '}.shuffle
