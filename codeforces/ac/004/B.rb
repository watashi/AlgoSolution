d, s = gets.split.map{|i| i.to_i}
min = []
max = []
d.times do
	mini, maxi = gets.split.map{|i| i.to_i}
	min <<= mini
	max <<= maxi
end

mins = min.inject{|i, j| i += j}
maxs = max.inject{|i, j| i += j}
if (mins .. maxs).include?(s) then
	diff = s - mins
	0.upto(d - 1).each do |i|
		max[i] = [max[i], min[i] + diff].min
		diff -= max[i] - min[i]
	end
	puts 'YES'
	puts max.join(' ')
else
	puts 'NO'
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
200403 	Nov 29, 2010 9:20:44 PM 	watashi 	B - Before an Exam 	Ruby 	Accepted 	80 ms 	3008 KB 

