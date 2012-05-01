def gao(n)
    unless $h[n]
        t = 1
        d = 2
        while d * d <= n
            if n % d == 0
                t = [t, gao(d), gao(n / d)].max
            end
            d += 1
        end
        $h[n] = n + t
    end
    return $h[n]
end

$h = {1 => 1}
n = gets.to_i
p gao(n)

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1643280 	Apr 29, 2012 8:44:07 AM 	watashi 	B2 - Rectangular Game (70 points) 	Ruby 	Accepted 	190 ms 	5500 KB
1643279 	Apr 29, 2012 8:44:00 AM 	watashi 	B1 - Rectangular Game (30 points) 	Ruby 	Accepted 	90 ms 	5500 KB
