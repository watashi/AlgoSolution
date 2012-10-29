if ENV['USER'] != 'watashi'
  $stdin = open('input.txt')
  $> = open('output.txt', 'w')
end

n = gets.to_i
m = 0
a = []
while 1 << m < n
  a << [*1..n].select{|_| _[m] == 1}
  m += 1
end

p a.size
a.each{|_|
  puts "#{_.size} #{_ * ' '}"
}
