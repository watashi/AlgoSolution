# @param {Integer[]} nums
# @return {Integer}
def count_distinct_integers(nums)
  Set.new(nums + nums.map{|i| i.to_s.reverse.to_i(10)}).size
end
