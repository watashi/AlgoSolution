n = 500
a = Array.new(n) do |i|
  Array.new(n) do |j|
    i == j ? 0 : rand(50000 .. 100000)
  end
end

puts n
puts a.map{|i| i * ' '} * "\n"
puts [*1..n].shuffle * ' '
