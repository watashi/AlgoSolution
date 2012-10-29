def gao(_)
    ('%08b' % _).reverse.to_i(2)
end

# s = gets.chomp
s = "INTERCAL"
i = 1
x = 0
s.each_byte do |b|
    y = (gao(x) - gao(b)) % 256
    puts "DO ,1 SUB ##{i} <- ##{y}"
    x = gao((gao(x) - y) % 256)
    i += 1
end
