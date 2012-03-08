p1, p2, p3, p4, a, b = gets.split.map(&:to_i)
p [*a .. b].count{|_| _ % p1 % p2 % p3 % p4 == _}
