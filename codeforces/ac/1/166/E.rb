require 'matrix'

MOD = 1000000007

def mul(a, b)
    (a * b).map{|_| _ % MOD}
end

a = Matrix.build(4, 4){|i, j| i == j ? 0 : 1}
b = Matrix.I(4)
n = gets.to_i
while n > 0
    b = mul(b, a) if n.odd?
    a = mul(a, a)
    n /= 2
end
p b[0, 0]
