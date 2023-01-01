require 'prime'
require 'set'

# @param {Integer[]} nums
# @return {Integer}
def distinct_prime_factors(nums)
  ps = Set.new
  nums.each do |i|
    i.prime_division.each do |j, _|
      ps << j
    end
  end
  ps.size
end
