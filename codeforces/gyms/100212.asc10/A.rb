BEGIN {
  if ENV['USER'] != 'watashi'
    $stdin = open('bomb.in')
    $> = open('bomb.out', 'w')
  end
}

def hypot(a, b)
  Math.hypot(a[0] - b[0], a[1] - b[1])
end

a = Array.new(3){ gets.split.map(&:to_f) }
x = hypot(a[0], a[1])
y = hypot(a[0], a[2])
z = hypot(a[1], a[2])
puts [x + y - z,
      x - y + z,
     -x + y + z].map{|i| i / 2} * "\n"
