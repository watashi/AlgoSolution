n, k = gets.split.map(&:to_i)
m = (n + 1) / 2
p k <= m ? 2 * k - 1 : 2 * (k - m)
