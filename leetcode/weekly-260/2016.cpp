class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int a = *max_element(nums.begin(), nums.end());
        int d = -1;
        for (int i: nums) {
            d = max(d, i - a);
            a = min(a, i);
        }
        return d > 0 ? d : -1;
    }
};
