WIDTH = 9

def diff(a, b)
  a = "%0#{WIDTH}d" % a
  b = "%0#{WIDTH}d" % b
  WIDTH.times.map{|i| a[i] == b[i] ? 1 : 0}.inject(&:+)
end

x = rand(10 ** WIDTH)
y = Array.new(50){rand(10 ** WIDTH)}

p x
p y.map{|i| "%0#{WIDTH}d" % i}
p y.map{|i| diff(x, i)}
