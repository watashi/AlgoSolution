IN = open('D.in', 'w')
OUT = open('D.out', 'w')
10000.times do |_|
    n = rand(1000000000000000000000)
    # n = _
    m = (n ^ (3 * n)).to_s(2).count('1')
    IN.puts n.to_s(2)
    OUT.puts m
end
