class Rect
	def initialize(x, y, z)
		@a1 = x + y - z
		@a2 = x + y + z
		@b1 = x - y - z
		@b2 = x - y + z
		@valid = z >= 0
	end

	[:a1, :a2, :b1, :b2].each do |i|
		class_eval <<-"end_eval"
			def #{i}
				@#{i}
			end

			attr_writer :#{i}
		end_eval
	end

	def valid?
		@valid &&= (@a1 <= @a2 && @b1 <= @b2)
	end

	def invalid!
		@valid = false
	end

	def cut!(x1, y1, x2, y2)
		@a1 = [@a1, x1 + y1].max
		@a2 = [@a2, x2 + y2].min
		@b1 = [@b1, x1 - y2].max
		@b2 = [@b2, x2 - y1].min
	end

	def **(o)
		!(@a2 <= o.a1 || o.a2 <= @a1) && !(@b2 <= o.b1 || o.b2 <= @b1)
	end

	def /(o)
		r = []
		if @a1 <= o.a1
			r << self.clone
			r[-1].a2 = o.a1
			@a1 = o.a1
		end
		if @a2 >= o.a2
			r << self.clone
			r[-1].a1 = o.a2
			@a2 = o.a2
		end
		if @b1 <= o.b1
			r << self.clone
			r[-1].b2 = o.b1
			@b1 = o.b1
		end
		if @b2 >= o.b2
			r << self.clone
			r[-1].b1 = o.b2
			@b2 = o.b2
		end
		r
	end
end

def gao(n, m, s, a)
	b = [Rect.new(0, 0, 10000)]
	a.each do |x, y|
		c = Rect.new(x, y, s)
		b.size.times do |j|
			next unless b[j] ** c
			b += b[j] / c
			b[j].invalid!
		end
		b.reject!{|_| !_.valid?}
	end
	b.map!{|_| _ / _}.flatten!
	b.each do |_|
		if _.a1 == _.a2
			s = _.a1
			_.cut!([1, s - m].max, [1, s - n].max, [n, s - 1].min, [m, s - 1].min)
			_.b1 += 1 unless s.odd? == _.b1.odd?	## !!
			_.b2 -= 1 unless s.odd? == _.b2.odd?
		else
			s = _.b1
			_.cut!([1, 1 + s].max, [1, 1 - s].max, [n, m + s].min, [m, n - s].min)
			_.a1 += 1 unless s.odd? == _.a1.odd?	## !!
			_.a2 -= 1 unless s.odd? == _.a2.odd?
		end
	end
	b.reject!{|_| !_.valid?}
end

I = open('input.txt')
O = open('output.txt', 'w')

n, m = I.gets.split.map(&:to_i)
k = I.gets.to_i
t = I.gets.split.map(&:to_i)
a = k.times.map{|i| [t[i + i], t[i + i + 1]]}

l = 0
r = n + m
while l < r do
	s = (l + r) / 2
	b = gao(n, m, s, a)
	unless b.empty? then
		l = s + 1
	else
		r = s
	end
end
r -= 1

if r == 0
	# RE8
	O.puts "1 1"
else
	q = []
	gao(n, m, r, a).each do |_|
		_.a1.upto(_.a2) do |i|
			_.b1.upto(_.b2) do |j|
			#	q << [(i + j) / 2, (i - j) / 2] if (i + j).even? && (i - j).even?
				if (i + j).even? && (i - j).even?
					O.puts "#{(i + j) / 2} #{(i - j) / 2}"
					exit
				end
			end
		end
	end
end
# q.sort!.uniq!
# O.puts "#{q[0][0]} #{q[0][1]}"

# TODO: IDEA
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
234678 	Dec 29, 2010 10:31:27 AM 	watashi 	C - Fire Again 	Ruby 	Accepted 	90 ms 	3060 KB 


