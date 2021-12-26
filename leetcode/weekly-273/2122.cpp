class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        int m = (int)nums.size();
        int n = m / 2;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= n; ++i) {
            vector<int> ret;
            vector<bool> mark(m, false);
            int lo = 0, hi = i;
            int k = nums[hi] - nums[lo];
            if (k == 0 || k % 2 != 0) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                while (lo < m && mark[lo]) {
                    ++lo;
                }
                if (lo == m) {
                    goto NEXT;
                }
                while (hi < m && nums[hi] < nums[lo] + k) {
                    ++hi;
                }
                if (hi == m || nums[hi] != nums[lo] + k) {
                    goto NEXT;
                }
                ret.push_back(nums[lo++]);
                mark[hi++] = true;
            }
            k /= 2;
            for (auto& j: ret) {
                j += k;
            }
            return ret;
NEXT:
            continue;
        }
        return vector<int>{};
    }
};
