I = ->{gets.split.map(&:to_i)}
F = ->(s, t, d){d == 0 ? 10 ** 10 : (d > 0 ? t - s : 1 - s) / d}
r, c = I[]
x, y = I[]
n = 0
I[][0].times do
    u, v = I[]
    m = [F[x, r, u], F[y, c, v]].min
    n += m
    x += m * u
    y += m * v
end
p n
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1292072 	Mar 5, 2012 10:48:35 PM 	watashi 	152B - Steps 	Ruby 	Accepted 	170 ms 	5500 KB
