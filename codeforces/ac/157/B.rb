gets
p Math::PI * gets.split.map{|_| _.to_f ** 2}.sort.inject{|i, j| j - i}
