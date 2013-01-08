#!/usr/bin/ruby

T = 10 ** 9
N = 10 ** 5

n = ARGV[0] ? ARGV[0].to_i : N
m = N

puts "#{n} #{m}"
n.times do
  puts [rand(1 .. T), rand(1 .. N), rand(1 .. N)] * ' '
end

