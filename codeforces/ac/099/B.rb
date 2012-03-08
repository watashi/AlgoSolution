n = gets.to_i
a = n.times.map{gets.to_i}
s = a.inject &:+
k = a.find_all{|_| _ != s / n}.map{|_| a.index _}
if s % n != 0 || (!k.empty? && k.size != 2)
	puts 'Unrecoverable configuration.'
elsif k.empty?
	puts 'Exemplary pages.'
else
	i, j = *k
	i, j = j, i if a[i] < a[j]
	puts "#{(a[i] - a[j]) / 2} ml. from cup ##{j + 1} to cup ##{i + 1}."
end

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#602734 	Aug 11, 2011 5:40:46 PM 	watashi 	99B - Help Chef Gerasim 	Ruby 	Accepted 	90 ms 	3600 KB 
