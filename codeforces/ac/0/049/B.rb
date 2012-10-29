gets
b=$_.each_char.max.to_i+1
x,y=$_.split.map{|i|i.to_i(b)}
p (x+y).to_s(b).size
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
229538 	Dec 24, 2010 5:59:54 PM 	watashi 	B - Sum 	Ruby 	Accepted 	90 ms 	5060 KB 
