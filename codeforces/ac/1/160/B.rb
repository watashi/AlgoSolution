n = gets.to_i
s = gets.chomp
t = [s[0, n], s[n, n]].map{|_| _.chars.to_a.sort}.transpose
puts t.all?{|i, j| i < j} || t.all?{|i, j| i > j} ? :YES : :NO
