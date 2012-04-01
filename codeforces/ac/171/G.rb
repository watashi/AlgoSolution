a, b, c = gets.split.map(&:to_i)
c.times do
    a, b = b, a + b
end
p a
