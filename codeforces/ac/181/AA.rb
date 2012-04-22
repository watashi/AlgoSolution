r,c=gets.split.map(&:to_i)
x,y=0,0
r.times{|i|gets;c.times{|j|x^=i and y^=j if $_[j]=='*'}}
puts "#{x+1} #{y+1}"
