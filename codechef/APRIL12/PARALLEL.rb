n = gets.to_i
a = []
m = 1
while m < n
    b = []
    (0 ... n).step(m << 1) do |s|
        b << [s + m, s + m + m] if s + m + m <= n
    end
    a << b unless b.empty?
    m <<= 1
end
while m > 1
    b = []
    (0 ... n).step(m) do |s|
        b << [s, s + m / 2] if 0 < s && s + m / 2 <= n
    end
    a << b unless b.empty?
    m >>= 1
end

p a.size
a.each do |b|
    puts "#{b.size} #{b.map{|s, t| "#{s}+#{t}=#{t}"} * ' '}"
end
# p a.size, a.map{|_| _.size}.inject(&:+)
