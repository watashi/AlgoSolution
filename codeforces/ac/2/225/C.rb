n, m, x, y = gets.split.map(&:to_i)
a = Array.new(n){gets.chomp.chars.to_a}
a = a.transpose.map{|_| _.count('#')}
w = [0] + [n * m] * m
b = [0] + [n * m] * m
x.upto(m) do |i|
    c = 0
    (i - 1).downto([i - y, 0].max) do |j|
        c += a[j]
        if i - j >= x
            w[i] = [w[i], b[j] + c].min
            b[i] = [b[i], w[j] + (i - j) * n - c].min
        end
    end
end
p [w.last, b.last].min
