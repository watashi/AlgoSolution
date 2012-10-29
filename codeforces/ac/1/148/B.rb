u, v, t, f, c = 5.times.map{gets.to_r}
d, k = u * t, 0
if v > u
    loop do
        d += d / (v - u) * u
        break if d >= c
        d += (d / v + f) * u
        k += 1
    end
end
p k
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1144134 	Feb 2, 2012 11:21:37 PM 	watashi 	148B - Escape 	Ruby 	Accepted 	200 ms 	5500 KB
