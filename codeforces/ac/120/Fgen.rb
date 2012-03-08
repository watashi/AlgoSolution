puts Array.new(200){Array.new(10){('a'.ord + rand(26).to_i).chr} * ''} * "\n"
