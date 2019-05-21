#!/usr/bin/ruby

def power(s)
  d = 0
  t = 1
  s.each_char do |c|
    if c == 'C'
      t *= 2
    elsif c == 'S'
      d += t
    end
  end
  # puts "#{s}: #{d}"
  d
end

re = gets.to_i
(1..re).each do |ri|
  d, s = gets.split
  d = d.to_i
  ans = 0
  while power(s) > d
    i = s.rindex('CS')
    if i.nil?
      ans = 'IMPOSSIBLE'
      break
    else
      ans += 1
      s[i, 2] = 'SC'
    end
  end
  puts "Case ##{ri}: #{ans}"
end
