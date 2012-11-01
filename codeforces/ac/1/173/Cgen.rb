r, c = 500, 500
puts "#{r} #{c}"
puts Array.new(r){ Array.new(c){ rand(-1000 .. 1000) } * ' ' }

