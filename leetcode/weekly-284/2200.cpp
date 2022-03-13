class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> v;
        int last = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                last = max(last, i - k);
                while (last < n && last <= i + k) {
                    v.push_back(last);
                    ++last;
                }
            }
        }
        return v;
    }
};
