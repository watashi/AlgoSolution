a, b, m, r = gets.split.map(&:to_i)
t, s = [nil] * r, 0
loop do
    if t[r]
        p s - t[r]
        break
    else
        t[r] = s
        r = (a * r + b) % m
        s += 1
    end
end
