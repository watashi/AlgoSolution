n, m = gets.split.map(&:to_i)
l = n / m
a = gets.split.map(&:to_f)
c = []
gets.to_i.times do
    b = gets.split.map{|_| _.to_i - 1}
    next unless a[b[0]]
    c << b.map{|_| a[_]}
    b.each{|_| a[_] = nil}
end
a.compact!
if a.size > n - m * l
    a.sort!
    c << a[0, l] << a.reverse[0, l]
end
c.map!{|_| _.inject(&:+)}
puts "#{c.min / l} #{c.max / l}"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1159784 	Feb 9, 2012 6:18:17 PM 	watashi 	119B - Before Exam 	Ruby 	Accepted 	110 ms 	5500 KB
