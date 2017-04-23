# @param {String} n
# @return {String}
def update(a, b, c)
    if (b == c)
        return a
    elsif (a - c).abs < (b - c).abs
        return a
    elsif (b - c).abs < (a - c).abs
        return b
    else
        return a < b ? a : b
    end
end

def nearest_palindromic(s)
    ans = 0
    n = s.size
    si = s.to_i
    ans = update(ans, ('1' + '0' * (n - 1) + '1').to_i, si)
    ans = update(ans, ('9' * (n - 1)).to_i, si)
    n1 = (n + 1) / 2
    n2 = n - n1
    pre = s[0...n1].to_i
    (-101..101).each do |i|
        x = (pre + i).to_s
        next if (pre + i) < 0 || x.size != n1
        y = x + x[0...n2].reverse
        ans = update(ans, y.to_i, si)
    end
    return ans.to_s
end
