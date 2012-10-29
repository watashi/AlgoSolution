if ENV['USER'] != 'watashi'
  $stdin = open('input.txt')
  $> = open('output.txt', 'w')
end

class RNG
  def initialize(x, a, b, c)
    @x = x
    @f = ->(x){(x * a + b) % c}
  end

  def next
    @x = @f[@x]
  end
end

n = gets.to_i
r = RNG.new(*gets.split.map(&:to_i))
a = Array.new(n){
  x, y = gets.split
  [y.to_i, x]
}
n /= 4
a = a.sort.reverse.each_slice(n).to_a
g = 'Group A:'
n.downto(1){|m|
  puts g
  g.succ!
  a.each{|b|
    t = b[r.next % m]
    puts t[1]
    b.delete(t)
  }
}
