a, x, y = gets.split.map(&:to_i)
b, i = -1, y / a
if i * a < y && y < (i + 1) * a
    if i == 0 || i.odd?
        b = i + i / 2 + 1 if x.abs * 2 < a
    else
        b = i + i / 2 + (x > 0 ? 1 : 0) if x != 0 && x.abs < a
    end
end
p b
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1146096 	Feb 3, 2012 11:58:18 AM 	watashi 	141B - Hopscotch 	Ruby 	Accepted 	110 ms 	5500 KB
