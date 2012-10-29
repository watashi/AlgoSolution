n = gets.to_i
t = gets.to_i
a = Array.new(n){
    b = gets.split.map(&:to_i)
    [*1..6] - b - b.map{|_| 7 - _}
}
puts a.uniq.size == 1 ? :YES : :NO
