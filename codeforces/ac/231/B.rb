n, d, m = gets.split.map(&:to_i)
y = n / 2
x = n - y
d -= x - y
a = Array.new(n) do |i|
  t = i.odd? == (d > 0) ? 0 : [d.abs, m - 1].min
  if d > 0
    d -= t
  else
    d += t
  end
  t + 1
end
puts d == 0 ? a * ' ' : -1
