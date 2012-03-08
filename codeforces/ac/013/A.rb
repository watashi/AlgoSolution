def s(n, b)
	n == 0 ? 0 : n % b + s(n / b, b)
end

n = gets.to_i
puts Rational(2.upto(n - 1).map{|b| s(n, b)}.inject(&:+), n - 2)

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
276018 	Feb 6, 2011 10:30:06 AM 	watashi 	13A - Numbers 	Ruby 	Accepted 	90 ms 	3000 KB 
