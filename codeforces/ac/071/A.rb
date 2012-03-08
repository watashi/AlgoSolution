gets.to_i.times do
	s = gets.chomp
	puts s.size > 10 ? "#{s[0]}#{s.size - 2}#{s[-1]}" : s
end
