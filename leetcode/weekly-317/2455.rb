# @param {Integer[]} nums
# @return {Integer}
def average_value(nums)
    x = nums.select{|i| i % 6 == 0}
    x.empty? ? 0 : x.sum / x.size
end
