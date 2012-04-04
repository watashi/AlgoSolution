N = 32768

class I
	def initialize(n)
		@n = n % N
	end

	attr_reader :n

	'+-*/'.each_char do |c|
		eval <<EOF
			def #{c}(o)
				return I.new(n #{c} o.n)
			end
EOF
	end

	def <=>(o)
		return n <=> o.n
	end

	include Comparable
end

y = I.new(gets.to_i)
s = (readlines * '')[/[^{]+(?=\})/].scan(/[^;]+(?=;)/).map do |_|
	_ = "if #{$1} then #{$2} end" if _ =~ /if(.*)(return.*)/
	_.gsub(/\d+/){"I.new(#{$&})"}
end

$f = Array.new(N)
eval <<EOF
def f(n)
	return $f[n.n] if $f[n.n]
	#{s * "\n"}
end
EOF

N.times{|i| $f[i] = f(I.new(i))}
p $f.rindex(y) || -1

__END__
# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
420315 	May 1, 2011 12:19:59 AM 	watashi 	39G - Inverse Function 	Ruby 	Accepted 	1220 ms 	5200 KB 
