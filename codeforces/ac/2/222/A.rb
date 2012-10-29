I = ->{ gets.split.map(&:to_i) }
n, k = I[]
a = I[]
b = a.rindex{|i| i != a[k - 1]} || -1
puts b < k - 1 ? b + 1 : -1
