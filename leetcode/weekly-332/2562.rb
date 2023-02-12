# @param {Integer[]} nums
# @return {Integer}
def find_the_array_conc_val(nums)
    n = nums.size
    s = 0
    (n / 2).times do |i|
        s += (nums[i].to_s + nums[-1 - i].to_s).to_i(10)
    end
    if n % 2 != 0
        s += nums[n / 2]
    end
    s
end
