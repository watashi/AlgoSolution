I = ->{gets.split.map &:to_i}
n, m = I[]
m -= 1
a = I[].sort
h = Hash.new(0)
a.each{|_| h[_] += 1}
h.sort.each{|k, v|
    if m < v * n
        m /= v
        puts "#{k} #{a[m]}"
        break
    else
        m -= v * n
    end
}
