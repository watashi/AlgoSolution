def gen(n)
  a = [rand(n)]
  puts n
  while a.size < n
    t = rand(n)
    next if a.include?(t)
    puts "#{a[rand(a.size)]} #{rand < 0.5 ? '<' : '>'} #{t}"
    a << t
  end
end

puts 55
1.upto(10).each do |n|
  n.times do
    gen(n)
  end
end
