_, x0, y0, x, y = gets.split.map(&:to_i)
x -= x0
y -= y0
gets.chomp.chars.each_with_index do |e, i|
  case e
  when 'E'
    x -= 1 if x > 0
  when 'S'
    y += 1 if y < 0
  when 'W'
    x += 1 if x < 0
  when 'N'
    y -= 1 if y > 0
  end
  if x == 0 && y == 0
    p i + 1
    exit
  end
end
p -1
