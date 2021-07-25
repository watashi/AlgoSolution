# @param {String} s
# @param {Integer} k
# @return {Integer}
def get_lucky(s, k)
  x = ''
  s.each_byte do |i|
    x += (i - ?a.ord + 1).to_s(10)
  end
  k.times do
    break if x.size == 1
    y = 0
    x.each_byte do |i|
      y += i - ?0.ord
    end
    x = y.to_s
  end
  x.to_i
end
