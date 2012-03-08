n, k = gets.split.map(&:to_i)
a = n.times.map{gets}
p k.times.to_a.permutation.map{|p|
	b = a.map{|s| (p.map{|_| s[_]} * '').to_i}
	b.max - b.min
}.min
