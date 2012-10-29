n=gets.to_i
a=gets.split.map &:to_i
s=a.inject &:+
2.upto(n/3){|m|
next if n%m!=0
m.times{|i|
t=(i...n).step(m).map{|_|a[_]}.inject &:+
s=t if s<t
}
}
p s
