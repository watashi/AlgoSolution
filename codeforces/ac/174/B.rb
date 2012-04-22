s = gets.chop
a = (s + '_' * 8).split('.')
if s[-1] != '.' && a.size > 1 && (1..8).cover?(a[0].size) && a[1..-1].all?{|_| (2..11).cover?(_.size)}
    puts :YES
    (1...a.size).each do |i|
        n = [1, a[i].size - 8].max
        puts "#{a[i - 1]}.#{a[i].slice!(0, n)}"
    end
else
    puts :NO
end
