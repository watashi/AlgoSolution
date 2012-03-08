$lucky = []

def gen(n, m)
	$lucky << m if m > 0
	if n > 0
		gen(n - 1, m * 10 + 4)
		gen(n - 1, m * 10 + 7)
	end
end

gen(4, 0)
n = gets.to_i
puts $lucky.map{|_| n % _}.index(0) ? :YES : :NO

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
863537 	Nov 14, 2011 7:23:51 PM 	watashi 	122A - Lucky Division 	Ruby 	Accepted 	80 ms 	3500 KB 

