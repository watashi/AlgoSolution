p 100
100.times do
  n = rand(1 .. 1111)
  k = rand(1 .. n)
  c = rand(1 .. 1000000000)
  puts "#{n} #{k} #{c}"
  puts Array.new(4){ rand(1 .. 100000000) } * ' '
  puts Array.new(4){ rand(1 .. 100000000) } * ' '
end
