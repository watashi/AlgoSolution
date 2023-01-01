require 'prime'

# @param {Integer} left
# @param {Integer} right
# @return {Integer[]}
def closest_primes(left, right)
  ps = Prime.each.take_while{|i| i <= right}.drop_while{|i| i < left}
  ps.each_cons(2).min_by{|i, j| j - i} || [-1, -1]
end
