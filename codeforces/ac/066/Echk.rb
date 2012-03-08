n = gets.to_i
a = gets.split.map(&:to_i)
b = gets.split.map(&:to_i)
puts <<EOF
	#{n} #{a.size} #{b.size}
	#{a.inject(&:+)}
	#{b.inject(&:+)}
EOF
