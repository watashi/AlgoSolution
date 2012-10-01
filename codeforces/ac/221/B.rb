s = gets
x = s.to_i
p [*1..x**0.5].map{|_| [_, x / _]}.flatten.select{|_| x % _ == 0 && s.tr(_.to_s, '') != s}.uniq.size
