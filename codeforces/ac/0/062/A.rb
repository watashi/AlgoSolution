gl, gr = gets.split.map(&:to_i)
bl, br = gets.split.map(&:to_i)
puts (gl <= br + 1 && br <= 2 * (gl + 1)) || (gr <= bl + 1 && bl <= 2 * (gr + 1)) ? :YES : :NO
