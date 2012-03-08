require 'date'
a, b = 2.times.map{gets.split('.').map(&:to_i).reverse}
a[0] += 2000
puts b.permutation.map{|c|
	c[0] += 2000
	begin
		Date.new(*a) >= Date.new(*c).next_year(18)
	rescue ArgumentError
		nil
	end
}.any? ? :YES : :NO
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
313726 	Mar 1, 2011 11:12:32 PM 	watashi 	30B - Codeforces World Finals 	Ruby 	Accepted 	160 ms 	4900 KB 
