d = gets.to_i
gets
p gets.split.map{|_| d - _.to_i}[0..-2].inject(&:+) || 0
