require 'prime'
N = 1000000
a = [true] * (N + 1)
b = []
(2 ... N).each do |p|
    next unless a[p]
    b << p if p.to_s.reverse.to_i.prime?
    (p ... N).step(p) do |q|
        a[q] = false
    end
end
p b.size
