k, n, m, q = gets.split.map(&:to_i)

c = Array.new(k){Hash.new{0}}

n.times do
	gets
end

h = Hash.new
m.times do
	if gets =~ /^(\w*):(.*)$/
		h[$1] = $2.split(/,/).map{|_| a, b = _.split; [a, b.to_i]}
	end
end

q.times do
	a, b = gets.split
	a = c[a.to_i - 1]
	a[b] += 1
	h.each do |k, v|
		next unless v.all?{|x, y| a[x] >= y}
		v.each do |x, y|
			a[x] -= y
		end
		a[k] += 1
	end
end

c.each do |a|
	a.reject!{|k, v| v == 0}
	p a.size
	a.to_a.sort.each do |k, v|
		puts "#{k} #{v}"
	end
end
