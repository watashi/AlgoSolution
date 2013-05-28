if ENV['USER'] != 'watashi'
  $stdin = open('positive.in')
  $> = open('positive.out', 'w')
end

n = gets.to_i
m = gets.count('-')
p [0, n - m - m].max
