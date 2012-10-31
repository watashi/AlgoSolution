n = 47
v = [*1..n].shuffle
e = 2.upto(n).map{|i| [i, i / 2].shuffle}.shuffle
p e.map{|i, _| i}
p e.map{|_, i| i}
