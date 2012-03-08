n = gets.to_i
a = []
Array.new(n) do
    m, w = gets.split
    b = [0, 0, 0, w]
    m.to_i.times do
        s = gets.gsub(/\D/, '')
        if s =~ /^(.)\1*$/
            b[0] += 1
        elsif s.chars.to_a.sort.uniq * '' == s.reverse
            b[1] += 1
        else
            b[2] += 1
        end
    end
    a << b
end
b = ['call a taxi', 'order a pizza', 'go to a cafe with a wonderful girl']

3.times do |i|
    c = a.map{|_| _[i]}.max
    d = a.select{|_| _[i] == c}.map{|_| _[3]}
    puts "If you want to #{b[i]}, you should call: #{d * ', '}."
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1235585 	Feb 26, 2012 2:35:53 AM 	watashi 	151B - Phone Numbers 	Ruby 	Accepted 	190 ms 	5500 KB
