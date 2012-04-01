I = ->{gets.split.map(&:to_i)}
n, a, b = I[]
c = I[].sort
p c[b] - c[b - 1]
