class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ret = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int a = nums[i], b = nums[i];
            for (int j = i + 1; j < (int)nums.size(); ++j) {
                a = min(a, nums[j]);
                b = max(b, nums[j]);
                ret += b - a;
            }
        }
        return ret;
    }
};
