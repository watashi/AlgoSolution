h, m = gets.split(/:/).map(&:to_i)
puts "#{30 * (h + m / 60.0) % 360} #{6.0 * m % 360}"
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
402137 	Apr 19, 2011 11:01:23 PM 	watashi 	80B - Depression 	Ruby 	Accepted 	90 ms 	3400 KB 
