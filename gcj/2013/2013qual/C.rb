$a = []
$a << %w(0 1 2 3)
$a << %w(00 11 22)
3.upto(50) do |n|
  a = []
  $a[-2].each do |i|
    %w(0 1 2).each do |j|
      k = ((j + i + j).to_i(10) ** 2).to_s
      k.sub!(/0*$/, '')
      a << j + i + j if k == k.reverse
    end
  end
  $a << a
  # puts "#{n} #{a.size}"
end

# $a.flatten!
# $a.reject!{|i| i[0] == '0'}
# p $a.size
$b = []
$a.each do |i|
  i.each do |j|
    $b << j.to_i ** 2 if j[0] != '0'
  end
end
$b.sort!
# p $b.size

def lower_bound(a, x)
  l = 0
  r = a.size
  while l < r
    m = (l + r) / 2
    if a[m] < x
      l = m + 1
    else
      r = m
    end
  end
  r
end

re = gets.to_i
1.upto(re) do |ri|
  l, r = gets.split.map(&:to_i)
  puts "Case ##{ri}: #{lower_bound($b, r + 1) - lower_bound($b, l)}"
end
