class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        int ret = -1;
        if (n == 1 && k % 2 == 1) {
            ret = -1;
        } else {
            if (k < n) {
                ret = max(ret, nums[k]);
            }
            if (k > 1) {
                ret = max(ret, *max_element(nums.begin(), nums.begin() + min(k - 1, n)));
            }
        }
        return ret;
    }
};
