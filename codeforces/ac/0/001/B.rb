gets.to_i.times do
	gets
	if /^(\D+)(\d+)$/ then
		puts "R#{$2}C#{(0..$1.size-1).map{|i|26**i}.inject{|i,j|i+j}+$1.tr('A-Z','0-9A-Z').to_i(26)}"
	elsif /R(.*)C/ then
		l,n=-1,$'.to_i
		n-=26**(l+=1) while n>=0
		n+=26**l
		puts n.to_s(26).tr('0-9a-z','A-Z').rjust(l,'A')+$1
	end
end

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
218682 	Dec 12, 2010 8:50:53 PM 	watashi 	B - Spreadsheet 	Ruby 	Accepted 	3190 ms 	3112 KB
