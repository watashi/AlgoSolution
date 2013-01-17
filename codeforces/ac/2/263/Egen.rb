if $*.size == 3
  n, m, k = *$*.map(&:to_i)
else
  n, m, k = 500, 500, 32
end

a = Array.new(n){Array.new(m){rand(10 .. 99)}}
puts [n, m, k] * ' '
puts a.map{|i| i * ' '}
