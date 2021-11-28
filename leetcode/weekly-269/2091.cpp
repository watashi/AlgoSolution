class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = (int)nums.size();
        int x = min_element(nums.begin(), nums.end()) - nums.begin();
        int y = max_element(nums.begin(), nums.end()) - nums.begin();
        if (x > y) {
            swap(x, y);
        }
        return min({y + 1, n - x, x + 1 + n - y});
    }
};
