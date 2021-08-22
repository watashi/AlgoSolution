# @param {Integer[]} nums
# @return {Integer}
def find_gcd(nums)
    nums.min.gcd(nums.max)
end
