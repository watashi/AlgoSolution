# @param {Integer} a
# @param {Integer} b
# @return {Integer}
def common_factors(a, b)
    g = a.gcd(b)
    1.upto(g).select{|i| g % i == 0}.size
end
