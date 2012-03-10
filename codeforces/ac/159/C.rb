class T
    def initialize(l, r)
        @l = l
        @r = r
        @m = (l + r) / 2
        @c = r - l
    end

    def l
        @pl = @pl || T.new(@l, @m)
    end

    def r
        @pr = @pr || T.new(@m, @r)
    end

    def c
        @c
    end

    def d(i)
        @c -= 1
        if @r - @l == 1
            @l
        elsif i < l.c
            l.d(i)
        else
            r.d(i - l.c)
        end
    end
end

r = gets.to_i
s = gets.chop
t = Array.new(128){T.new(0, r * s.size)}
d = Array.new(128){[]}
gets.to_i.times{|i|
    p, c = gets.split
    c = c.ord
    d[c] << t[c].d(p.to_i - 1)
}
d.each{|_|
    _.sort!.reverse!
}
t = [0] * 128
z = []
r.times{
    s.each_byte{|b|
        if t[b] == d[b][-1]
            d[b].pop
        else
            z << b
        end
        t[b] += 1
    }
}
puts z.map(&:chr) * ''
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1338602 	Mar 10, 2012 10:37:54 PM 	watashi 	C - String Manipulation 1.0 	Ruby 	Accepted 	690 ms 	14900 KB
