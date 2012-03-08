line = gets.chomp
line.gsub!(/ *, */, ', ')
line.gsub!(/ *\.\.\. */, ' ...')
line.gsub!(/ +/, ' ')
line.strip!
puts line
