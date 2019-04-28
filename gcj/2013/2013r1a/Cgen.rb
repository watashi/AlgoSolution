#!/usr/bin/ruby

ANS = open('answer', 'w')
ANS.puts "Case #1:"

RE = 1
# R, N, M, K = 100, 3, 5, 7
R, N, M, K = 8000, 12, 8, 12
# R, N, M, K = 1000, 10, 8, 10

puts RE
puts [R, N, M, K] * ' '
R.times do
  a = Array.new(N){ rand(2 .. M) }
  b = Array.new(K) do
    a.select{ rand < 0.5 }.inject(1, &:*)
  end
  puts b * ' '
  ANS.puts a.sort * ''
end
