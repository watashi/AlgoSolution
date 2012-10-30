h = Hash.new(0)
gets.to_i.times{
  h[gets] += 1
}
p h.values.max
