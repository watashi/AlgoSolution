# @param {Integer[]} nums
# @return {Integer}
def find_max_k(nums)
    st = Set.new(nums)
    nums.select{|i| i > 0 && st.include?(-i)}.max || -1
end
