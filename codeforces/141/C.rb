n = gets.to_i
a = n.times.map{
    x, y = gets.split
    [y.to_i, x]
}.sort
b = []
a.each do |x, y|
    break if x > b.size
    b.each{|_| _[1] += 1 if _[1] >= x}
    b << [y, x]
end
puts b.size < n ? -1 : b.map{|i, j| "#{i} #{n - j}"} * "\n"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1146150 	Feb 3, 2012 12:15:30 PM 	watashi 	141C - Queue 	Ruby 	Accepted 	880 ms 	5500 KB
