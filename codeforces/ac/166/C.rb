I = ->{gets.split.map(&:to_i)}
n, m = I[]
c = [0] * 3
I[].each{|_| c[(_ <=> m) + 1] += 1}
d = 0
if c[1] == 0
    c[1] += 1
    d += 1
end
d += [(c[0] > c[2] ? c[0] - c[2] + 1 : c[2] - c[0]) - c[1], 0].max
p d
