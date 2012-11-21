n = 200000
m = 200000
a = []
(m * 6 / 10).times do
  k = rand(1 .. 1000000)
  a << k
  a << k if rand < 0.9
end
a = a.shuffle[0, m]

puts "#{n} #{m}"
b = {}
a.each do |i|
  unless b[i]
    b[i] = 1
    puts "1 #{i}"
  else
    b[i] = nil
    puts "2 #{i}"
  end
end
