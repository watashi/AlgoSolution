def idx(x)
  if x < -333333333
    0
  elsif x < 333333333
    1
  else
    2
  end
end

n = 100000
a = [0] * 9

puts n
n.times do
  x, y = *Array.new(2){rand(-10**9 .. 10**9)}
  puts "#{x} #{y}"
  a[idx(x) * 3 + idx(y)] += 1
end
puts a * ' '

