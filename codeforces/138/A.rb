n, m = gets.split.map(&:to_i)
b = [true] * 4
n.times do
    a = Array.new(4){gets[/([aeiou][^aeiou]*){#{m}}$/]}
    1.upto(3) do |i|
        if b[i]
            b[i] &= a[0] && a[0] == a[i]
            j = i != 1 ? 1 : 2
            k = i != 3 ? 3 : 2
            b[i] &= a[j] && a[j] == a[k]
        end
    end
end

if b.all?
    puts :aaaa
elsif b[1]
    puts :aabb
elsif b[2]
    puts :abab
elsif b[3]
    puts :abba
else
    puts :NO
end
__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
1152132 	Feb 6, 2012 6:59:38 AM 	watashi 	138A - Literature Lesson 	Ruby 	Accepted 	300 ms 	5800 KB
