s = gets.chop
n = nil
if s[0] == '-'
    s = s[1..-1]
    n = true
end
i, f = s.split('.')
f = (f || '') + '00'
s = "$#{i.gsub(/(?<=.)(?=(.{3})+$)/, ',')}.#{f[0, 2]}"
puts n ? "(#{s})" : s
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1120360 	Jan 27, 2012 2:28:21 PM 	watashi 	143B - Help Kingdom of Far Far Away 2 	Ruby 	Accepted 	110 ms 	5500 KB 
