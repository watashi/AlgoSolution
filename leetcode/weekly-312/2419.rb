# @param {Integer[]} nums
# @return {Integer}
def longest_subarray(nums)
    k = nums.max
    nums.slice_when{|i, j| i != j}.filter{|i| i.first == k}.map(&:size).max
end
