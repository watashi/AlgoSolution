def rem(n)
    [2, 3, 5, 7].each do |m|
        n /= m while n % m == 0
    end
    return n
end

def gao(n)
    n += 1 while rem(n) != 1
    return n
end

loop do
    n = gets.to_i
    puts "#{n}:"
    10.times do
        n = gao(n)
        p n
        n += 1
    end
    puts
end
