class Solution {
public:
    int countElements(vector<int>& nums) {
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        if (a == b) {
            return 0;
        } else {
            a = count(nums.begin(), nums.end(), a);
            b = count(nums.begin(), nums.end(), b);
            return nums.size() - a - b;
        }
    }
};
