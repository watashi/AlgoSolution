N = 12

c = Array.new(N + 1){ [0] * (N + 1) }

0.upto(N) do |i|
  c[i][0] = 1
  1.upto(i) do |j|
    c[i][j] = c[i - 1][j - 1] + c[i - 1][j]
  end
end

c.each do |i|
  p i
end

ans = Array.new(N + 1){ [nil] * (N + 1) }

2.upto(N) do |b|
  ans[0][b] = Rational(1, b - 1)
# ans[1][b] = Rational(b, (b - 1) ** 2)
end

1.upto(N) do |a|
  2.upto(N) do |b|
    ans[a][b] = Rational(1)
    0.upto(a - 1) do |i|
      ans[a][b] += ans[i][b] * c[a][i]
    end
    ans[a][b] /= b - 1
  end
end

ans.each do |i|
  p i
end

ans.each do |i|
  puts '{' + i.map{|j| j.to_s.inspect} * ', ' + '},'
end
