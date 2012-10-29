a = gets.chomp
b = gets.chomp
c = (a.to_i + b.to_i).to_s
x, y, z = [a, b, c].map{|_| _.gsub(/0/, '').to_i}
puts x + y == z ? :YES : :NO
