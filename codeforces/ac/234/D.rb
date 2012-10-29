if ENV['USER'] != 'watashi'
  $stdin = open('input.txt')
  $> = open('output.txt', 'w')
end

I = ->{gets.split.map(&:to_i)}
m, k = I[]
f = I[]
n, _ = I[]
a = Array.new(n){
  I[]
  I[]
  b = I[]
  x = b.count{|_| f.index(_)}
  y = b.count(0)
  [[x + y, k].min, [x, b.size - (m - k)].max]
}
puts a.map{|i|
  a.all?{|j| i === j || i[1] >= j[0]} ?
    0 :
    a.all?{|j| i[0] >= j[1]} ? 2 : 1
} * "\n"
