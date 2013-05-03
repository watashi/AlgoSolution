
c = [*1..40].select(&:even?)
c += [1, 3]

a = Array.new(50) do
  Array.new(50) do
    '.'
  end
end

c.zip(50.times.select(&:odd?)) do |k, i|
  k.times do |j|
    a[i][j] = 'v'
  end
end

p c.select(&:odd?).size
p c.select(&:even?).size
puts a.map{|i| '"' + i * '' + '"'} * ",\n"
p 1
