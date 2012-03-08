y = 3.times.map{gets.split.map(&:to_i)}.inject(&:concat)
(1..9).each do |a|
    (1..9).each do |b|
        (1..9).each do |c|
            (1..9).each do |d|
                x = [a + b, c + d, a + c, b + d, a + d, b + c]
                if [a, b, c, d].uniq.size == 4 && x == y
                    puts "#{a} #{b}\n#{c} #{d}"
                    exit
                end
            end
        end
    end
end
p -1
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1120320 	Jan 27, 2012 2:11:22 PM 	watashi 	143A - Help Vasilisa the Wise 2 	Ruby 	Accepted 	130 ms 	5500 KB
