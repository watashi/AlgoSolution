$s = [0]
$a = [0]
n, m = gets.split.map(&:to_i)
n.times do
    $s << $s[-1] * 4 + 3
    $a << $a[-1] * 2 + 1
end

def gao(n, m)
    return [0, 0] if n == 0
    n -= 1
    if m <= $s[n]
        x, y = gao(n, m)
    elsif m <= $s[n] * 2 + 1
        x, y = gao(n, m - ($s[n] + 1))
        x, y = [y, $a[n] + 1 + x]
    elsif m <= $s[n] * 3 + 2
        x, y = gao(n, m - ($s[n] * 2 + 2))
        x, y = [$a[n] + 1 + y, $a[n] + 1 + x]
    else
        x, y = gao(n, m - ($s[n] * 3 + 3))
        x, y = [$a[n + 1] - x, $a[n] - y]
    end
    return [y, x]
end

x, y = gao(n, m)
# x, y = y, x if gao(n, 1) == [0, 1]
puts "#{y} #{x}"
