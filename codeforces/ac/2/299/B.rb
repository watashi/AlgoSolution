k = gets.split[1].to_i
puts (gets.chomp.split('.').map(&:size).max || -1) >= k ? :NO : :YES
