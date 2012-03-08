require 'prime'

n = gets.to_i
if n == 2
	p -1
	exit
end

a = []
Prime.each do |prime|
	a << prime
	break if a.size == n
end
s = a.inject(&:*)
a = a.map{|_| s / _}
puts a * "\n"
__END__
n.times do |i|
	p a[i] if a[i].to_s.size > 100
	i.times do |j|
		p "#{a[i]} #{a[j]}" if a[i].gcd(a[j]) == 1
	end
end
p "555" if a.inject(&:gcd) > 1
