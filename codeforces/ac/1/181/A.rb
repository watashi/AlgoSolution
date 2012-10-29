r, c = gets.split.map(&:to_i)
x, y = 0, 0
1.upto(r){|i|
    gets
    1.upto(c){|j|
        if $_[j - 1] == '*'
            x ^= i
            y ^= j
        end
    }
}
puts "#{x} #{y}"
