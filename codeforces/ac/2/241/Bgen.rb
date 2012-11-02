n = 50000
m = rand(n * (n - 1) / 2)
puts "#{n} #{m}"
puts Array.new(n){ rand(0 .. 10 ** 9) } * ' '
