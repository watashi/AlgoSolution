a, b = gets.split.map(&:to_i)
p a + b - 1
puts "1 1"
2.upto(a) do |i|
  puts "#{i} 1"
end
2.upto(b) do |i|
  puts "1 #{i}"
end
