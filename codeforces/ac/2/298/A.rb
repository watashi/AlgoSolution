gets
gets
if x = $_ =~ /R+[^L]?/
  puts "#{x + 1} #{x + $&.size}"
elsif x = $_ =~ /L+/
  puts "#{x + $&.size} #{x}"
end
