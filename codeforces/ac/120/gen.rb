p 100000
puts Array.new(100000){"#{rand(20000).to_i - 10000} #{rand(20000).to_i - 10000}"} * "\n"
