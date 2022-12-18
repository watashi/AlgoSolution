require 'prime'
require 'set'

# @param {Integer} n
# @return {Integer}
def smallest_value(n)
    ret = n
    done = Set.new
    until done.include?(n)
        done << n
        n = n.prime_division.map{|i, j| i * j}.sum
        ret = [ret, n].min
    end
    ret
end
