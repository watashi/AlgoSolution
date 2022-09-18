# @param {Integer} n
# @return {Integer}
def smallest_even_multiple(n)
    n.odd? ? n * 2 : n
end
