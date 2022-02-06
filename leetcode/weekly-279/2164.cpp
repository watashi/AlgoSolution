class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> odd, even;
        for (int i = 0; i < (int)nums.size(); i += 2) {
            even.push_back(nums[i]);
        }
        for (int i = 1; i < (int)nums.size(); i += 2) {
            odd.push_back(nums[i]);
        }
        sort(odd.rbegin(), odd.rend());
        sort(even.begin(), even.end());
        vector<int> v(nums.size());
        for (int i = 0; i < (int)nums.size(); i += 2) {
            v[i] = even[i / 2];
        }
        for (int i = 1; i < (int)nums.size(); i += 2) {
            v[i] = odd[i / 2];
        }
        return v;
    }
};
