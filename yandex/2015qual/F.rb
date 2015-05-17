#!/usr/bin/ruby

n = gets.to_i
config = n.times.map do
  gets.split.map(&:to_i)
end

gets
c = Hash.new(0)
gets.split.map(&:to_i).each do |i|
  c[i - 1] += 1
end

config.each_with_index do |e, i|
  l, r = *e
  if c[i] < l
    puts 'Green'
  elsif c[i] > r
    puts 'Red'
  else
    puts 'Orange'
  end
end
