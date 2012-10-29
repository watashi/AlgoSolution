if ENV['USER'] != 'watashi'
  ARGV << 'input.txt'
  $> = open('output.txt', 'w')
end

n = gets.to_i / 2
m = gets
puts [*1..n].map{|i| (m[i-1] == 'L' ? [i, n+i] : [n+i, i]) * ' '} * "\n"
