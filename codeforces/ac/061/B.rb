def gao(s)
	_ = s.downcase.gsub(/[^a-z]/, '')
end

a = [gets, gets, gets].permutation.map{|_| gao(_ * '')}
gets.to_i.times do
	puts a.member?(gao(gets)) ? :ACC : :WA
end

