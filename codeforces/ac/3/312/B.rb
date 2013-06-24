a, b, c, d = gets.split.map(&:to_f)
a /= b
c /= d
x = (1 - a) * (1 - c)
y = (1 - a) * c
p 1 - y / (1 - x)
