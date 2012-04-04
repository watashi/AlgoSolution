def choose(n, m)
    n < m ? 0 : m.times.inject(1){|i, j| i * (n - j) / (j + 1)}
end

n, m, t = gets.split.map(&:to_i)
ans = choose(n + m, t) - choose(n, t) * choose(m, 0)
4.times do |i|
    ans = ans - choose(n, i) * choose(m, t - i)
end
p ans
