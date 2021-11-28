class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int64_t> s(n + 1);
        vector<int> ret(n, -1);
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        for (int i = k; i + k < n; ++i) {
            ret[i] = (s[i + k + 1] - s[i - k]) / (k + k + 1);
        }
        return ret;
    }
};
