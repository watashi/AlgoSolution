s = gets.chomp
s = '1' + s if s[0] == '0'
m = 1
m += 1 while m < s.size && s[m] == '0'
a = s[0, m].to_i
b = s[m .. -1]

if a.to_s.start_with?(b) && (a + 1).to_s.start_with?(b)
    d = 1
elsif b.to_i <= a.to_i
    while b.to_i <= a.to_i
        b += '0'
    end
    d = b.to_i - a.to_i
else
    d = b.to_i - a.to_i
    a.to_s.size.upto(b.size - 1) do |i|
        t = b[0, i].to_i - a
        r = b[i .. -1]
        if t > 0
            c = a + t
            while r.size > 0
                c += t
                h = c.to_s
                j = [r.size, h.size].min
                break unless r.start_with?(h[0, j])
                r = r[j .. -1]
            end
            if r.size == 0
                d = t
                break
            end
        end
    end
end

puts "#{a} #{d}"
