gets
s = gets.chop
print s.slice!(0..1)+'-' if s.size % 3 == 1
s.gsub!(/.../){$&+'-'}
s.chop! if s =~ /-$/
puts s

__END__
# ruby1.8
gets
gets
chop!
print $_.slice!(0..1)+'-' if $_.size % 3 == 1
gsub!(/.../){$&+'-'}
chop! if /-$/
puts $_

# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219413 	Dec 15, 2010 4:35:10 PM 	watashi 	B - Phone numbers 	Ruby 	Accepted 	90 ms 	3000 KB 
