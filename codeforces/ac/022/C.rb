n, m, v = gets.split.map(&:to_i)
if m < n - 1 || m > (n - 1) * (n - 2) / 2 + 1 then
	p -1
else
	w = v == 1 ? 2 : 1
	puts "#{v} #{w}"
	a = [*1..n]
	a.delete(w)
	[*0..a.size-2].each{|i| puts "#{a[i]} #{a[i + 1]}"}
	m -= n - 2
	[*0..a.size-1].each{|i|
		[*i+2..a.size-1].each{|j|
			exit if (m -= 1) == 0
			puts "#{a[i]} #{a[j]}"
		}
	}
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219399 	Dec 15, 2010 3:50:38 PM 	watashi 	C - System Administrator 	Ruby 	Accepted 	910 ms 	5752 KB 
