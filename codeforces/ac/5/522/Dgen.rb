#!/usr/bin/ruby

n = 500000
m = 500000
puts "#{n} #{m}"
puts Array.new(n){ rand(1..n) } * ' '
m.times do
  a = rand(1..n)
  b = rand(1..n)
  puts "#{[a, b].min} #{[a, b].max}"
end
