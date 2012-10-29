gets
a = []
gets.split.map(&:to_i).each do |b|
    a << b if a.empty? || b < a.min || b > a.max
end
p a.size - 1

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1235538 	Feb 26, 2012 1:58:37 AM 	watashi 	155A - I_love_%username% 	Ruby 	Accepted 	200 ms 	5500 KB
