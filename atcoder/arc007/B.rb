n, m = gets.split.map(&:to_i)
a = (n + 1).times.to_a
m.times do
    k = a.index(gets.to_i)
    a[0], a[k] = a[k], a[0]
end
puts a[1 .. -1] * "\n"
