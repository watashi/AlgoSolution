n = 100000
m = 100000
e = Array.new(m) {
  [rand(n) / 2 * 2, rand(n) / 2 * 2 + 1]
}
puts "#{n} #{m}"
puts e.map{|i| i.map(&:succ) * ' '}
