a = [
	[(-128 .. 127), :byte],
	[(-32768 .. 32767), :short],
	[(-2147483648 .. 2147483647), :int],
	[(-9223372036854775808 .. 9223372036854775807), :long]]
n = gets.to_i
a.each do |r, t|
	if r.include? n
		puts t
		exit
	end
end
puts :BigInteger
