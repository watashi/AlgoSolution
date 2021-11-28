# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def target_indices(nums, target)
    a = nums.sort
    a.size.times.select{|i| a[i] == target}.to_a
end
