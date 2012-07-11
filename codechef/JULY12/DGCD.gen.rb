N = 50000
M = 50000

e = Array.new(N){|i|
    if i == 0
        -1
    else
        # 0
        # i - 1
        # rand(i)
        [rand(i), i - 1 - rand(10)].max
    end
}
v = N.times.to_a #.shuffle

p N
e.each_with_index do |j, i|
    next if j == -1
    puts "#{v[i]} #{v[j]}"
end
puts Array.new(N){rand(M)} * ' '

p M
M.times do
    if rand(2) == 0
        puts "F #{rand(N)} #{rand(N)}"
    else
        puts "C #{rand(N)} #{rand(N)} #{rand(M)}"
    end
end
