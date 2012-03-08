def dfs(f, b, v)
	until b[v] do
		b[v] = 1
		v = f[v]
	end
	v
end

n = gets.to_i
f = [0] + gets.split.map(&:to_i)
a = [nil]*(n+1)
b = [nil]*(n+1)
r = []

f.each{|i| a[i] = 1}
[*1..n].each{|i| r << [i, dfs(f, b, i)] unless a[i]}
[*1..n].each{|i| r << [i, dfs(f, b, i)] unless b[i]}
r = [] if a[1..n].all? && r.size == 1
p r.size
r.each_index{|i| puts "#{r[i - 1][1]} #{r[i][0]}"}

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
219380 	Dec 15, 2010 3:11:10 PM 	watashi 	E - Scheme 	Ruby 	Accepted 	810 ms 	20692 KB 
