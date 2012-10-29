s, k = gets.split.map(&:to_i)
a = [1]
while a.last < s
    a << a[[0, a.size - k].max .. -1].inject(&:+)
end
b = [0]
a.reverse.each do |i|
    if i <= s
        s -= i
        b << i
    end
end
puts b.size
puts b * ' '
