h = Hash.new{[]}
n = gets.to_i
gets.split.map(&:to_i).each_with_index do |i, k|
    h[i] <<= k
end

a, b = 0, 0
gets
gets.split.map(&:to_i).each do |i|
    k = h[i]
    a += k[0] + 1
    b += n - k[-1]
end

puts "#{a} #{b}"
