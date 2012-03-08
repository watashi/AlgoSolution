def gao1(a, b)
	c = 0
	4.times{|i| c += 1 if a[i] == b[i]}
	c
end

def gao2(a, b)
	c = 0
	4.times{|i| c += 1 if b.index(a[i])}
	c
end

n = gets.to_i
x = 100.upto(9999).map{|_| '%04d' % _}
x.reject!{|_| _.bytes.sort.uniq.size < 4}
n.times do
	a, b, c = gets.split.map(&:to_i)
	a = '%04d' % a
	c += b
	x.reject!{|_| gao1(_, a) != b || gao2(_, a) != c}
end

if x.empty?
	puts 'Incorrect data'
elsif x.size > 1
	puts 'Need more data'
else
	puts x[0]
end
