def to_r(n)
	if n < 1
		''
	elsif n < 10
		%w(I II III IV V VI VII VIII IX)[n - 1]
	elsif n < 100
		%w(X XX XXX XL L LX LXX LXXX XC)[n / 10 - 1] + to_r(n % 10)
	elsif n < 1000
		%w(C CC CCC CD D DC DCC DCCC CM)[n / 100 - 1] + to_r(n % 100)
	else
		%w(M MM MMM)[n / 1000 - 1] + to_r(n % 1000)
	end
end

a, b = gets.split.map(&:to_i)
n = gets.to_i(a)
puts b > 0 ? n.to_s(b).upcase : to_r(n)
