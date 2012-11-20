puts 'a' * 5000
1000000.times do
  l = rand(1 .. 5000)
  r = rand(1 .. 5000)
  l, r = r, l if l > r
  puts "#{l} #{r}"
end
