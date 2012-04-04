s = gets.chomp
s.swapcase! if s =~ /^.[A-Z]*$/
puts s
