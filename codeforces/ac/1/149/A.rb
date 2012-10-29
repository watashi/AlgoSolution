k = gets.to_i
a = gets.split.map(&:to_i)
0.upto(12) do |n|
    a.combination(n) do |b|
        if b.inject(0, &:+) >= k
            p n
            exit
        end
    end
end
p -1
