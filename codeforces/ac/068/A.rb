p1, p2, p3, p4, a, b = gets.split.map(&:to_i)
ps = [p1, p2, p3, p4]
p [*a .. b].count{|_| ps.permutation.count{|px| px.inject(_){|i, j| i % j} == _} >= 7}
