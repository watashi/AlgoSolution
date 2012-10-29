if ENV['USER'] != 'watashi'
  $stdin = open('input.txt')
  $> = open('output.txt', 'w')
end

I = ->{gets.split.map(&:to_i)}
n, m = I[]
a = I[].zip([*1..n]).sort[n - m, m]
p a[0][0]
puts a.map{|_| _[1]} * ' '
