def gen(n, a)
  b = []
  a.each do |i|
    [*0..3].product(*Array.new(n - 1, [*0..3])).each do |j|
      t = i.clone
      t << 0
      n.times do |k|
        t[k] += j[k]
        t[n] += 3 - j[k]
      end
      b << t.sort
    end
  end
  b.uniq
end

ans = []
ans << [] << [[0]]
1.upto(5) do |n|
  ans << gen(n, ans[n])
  p ans.last.size
end
p ans[4]
