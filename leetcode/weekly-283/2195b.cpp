class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for (int i: nums) {
            if (i <= k) {
                ans -= i;
                ++k;
            } else {
                break;
            }
        }
        ans += (1LL + k) * k / 2;
        return ans;
    }
};
