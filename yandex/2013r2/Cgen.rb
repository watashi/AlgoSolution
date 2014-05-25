a = Array.new(2000) do
  [rand(-1000000000 .. 1000000000), rand(-1000000000 .. 1000000000)] * ' '
end
puts a.size
puts a
