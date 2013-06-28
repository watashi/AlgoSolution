gets
a = gets.split.map(&:to_i)
b = a.size - 1
while b > 0 do
  break if a[b - 1] > a[b]
  b -= 1
end
p b
