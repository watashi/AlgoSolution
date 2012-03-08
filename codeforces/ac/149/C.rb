n = gets.to_i
a = gets.split.map(&:to_i).zip(1.upto(n)).sort.reverse
l, r, x, y = 0, 0, [], []

if n.odd?
    b = a.pop
    l += b[0]
    x << b[1]
end

(n / 2).times do
    b = a.pop
    c = a.pop
    b, c = c, b if l <= r
    l += b[0]
    x << b[1]
    r += c[0]
    y << c[1]
end

p x.size
puts x * ' '
p y.size
puts y * ' '
