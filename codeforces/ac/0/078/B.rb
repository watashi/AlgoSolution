n = gets.to_i
s = 'ROY'
3.upto(n - 1){|i| s << 'GBIV'[i % 4]}
puts s
