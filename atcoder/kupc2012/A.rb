n, t, e = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)
a.each_with_index do |x, i|
    y = (t + e) / x * x
    if y >= t - e
        p i + 1
        exit
    end
end
p -1
