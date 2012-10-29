a = gets.scan(/\d/).map(&:to_i)
c = [0] * 10
gets.scan(/\d/) do |_|
    c[_.to_i] += 1
end
a.size.times do |i|
    k = c.rindex{|_| _ > 0}
    if k && k > a[i]
        a[i] = k
        c[k] -= 1
    end
end
puts a * ''
