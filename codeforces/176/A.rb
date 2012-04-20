n, m, k = gets.split.map(&:to_i)
a = Array.new(n) do
    gets
    Array.new(m) do
        gets.split.map(&:to_i)
    end
end

ans = 0
a.permutation(2) do |x, y|
    z = []
    m.times do |i|
        z <<= [y[i][1] - x[i][0], x[i][2]]
    end
    tmp = 0
    rem = k
    z.sort.reverse.each do |i, j|
        num = [rem, j].min
        tmp += i * num if i > 0
        rem -= num
    end
    ans = [ans, tmp].max
end
p ans
