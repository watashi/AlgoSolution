# @param {String[]} nums
# @return {String}
def find_different_binary_string(nums)
    n = nums.size
    h = {}
    nums.each{|i| h[i.to_i(2)] = true}
    (2 ** n).times do |i|
        next if h[i]
        s = i.to_s(2)
        s = '0' * (n - s.size) + s
        return s
    end
end
