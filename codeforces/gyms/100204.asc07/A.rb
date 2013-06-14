BEGIN {
  if ENV['USER'] != 'watashi'
    $stdin = open('assign.in')
    $> = open('assign.out', 'w')
  end
}

n = gets.to_i
a = Array.new(n) do |i|
  Array.new(n) do |j|
    i == 0 ? [j, 1].min : i <= j ? 2 : 0
  end
end
puts a.map{|i| i * ' '} * "\n"
