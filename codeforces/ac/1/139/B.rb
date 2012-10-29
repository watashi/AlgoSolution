n = gets.to_i
a = Array.new(n) do
    l, w, h = gets.split.map(&:to_i)
    [h, 2 * (l + w)]
end
m = gets.to_i
b = Array.new(m) do
    gets.split.map(&:to_i)
end

s = 0
a.each do |x, y|
    t = 9e9
    b.each do |u, v, w|
        u /= x
        next if u == 0
        v *= u
        t = [t, (y + v - 1) / v * w].min
    end
    s += t
end
p s

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1127793 	Jan 31, 2012 9:15:20 AM 	watashi 	139B - Wallpaper 	Ruby 	Accepted 	250 ms 	5500 KB
