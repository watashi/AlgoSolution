I = open('input.txt')
O = open('output.txt', 'w')
T, K = I.gets.split.map(&:to_i)
T.times do
	n, m = I.gets.split.map{|_| _.to_i - 1}.sort
	O.puts n % (K + 1) == K || (n + m - (K == 1 ? 0 : n / (K + 1))).odd? ? :+ : :-
end

__END__
WA3: K=1
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
236018 	Jan 2, 2011 8:23:54 PM 	watashi 	D - New Game with a Chess Piece 	Ruby 	Accepted 	80 ms 	2992 KB
