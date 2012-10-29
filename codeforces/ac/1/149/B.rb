S = [*'0'..'9'] + [*'A'..'Z']
def gao(s, b)
    x = 0
    s.each_char do |c|
        x *= b
        i = S.index(c)
        return nil unless i && i < b
        x += i
    end
    return x
end

a, b = gets.chop.split(/:/).map{|_| _.gsub(/^0*(?=.)/, '')}
c = []
2.upto(100) do |d|
    x = gao(a, d)
    y = gao(b, d)
    c << d if x && x < 24 && y && y < 60
end

if c.empty?
    p 0
elsif c[-1] > 60
    p -1
else
    puts c * ' '
end
