def gao(_)
    ('%08b' % _).reverse.to_i(2)
end

s = gets.chomp
x = 0
s.each_byte do |b|
    y = (gao(x) - gao(b)) % 256
    p y
    x = gao((gao(x) - y) % 256)
end
