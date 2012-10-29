puts '.' + gets.chop.scan(/[^aeiouy]/i).to_a.map(&:downcase) * '.'
