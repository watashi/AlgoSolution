n, vb, vs = gets.split.map{|i| i.to_f}
x = gets.split.map{|i| i.to_i}
xu, yu = gets.split.map{|i| i.to_i}
ans = [1e100, -1, -1]
1.upto(x.length - 1) do |i|
	d = (xu - x[i]) ** 2 + yu ** 2
	t = x[i] / vb + Math.sqrt(d) / vs
	ans = [t, d, i] if t < ans[0] - 1e-6 || (t < ans[0] + 1e-6 && d < ans[1])
end
p ans[2] + 1

## 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
#209200 	Dec 6, 2010 6:25:29 PM 	watashi 	B - Running Student 	Ruby 	Accepted 	90 ms 	2992 KB 

