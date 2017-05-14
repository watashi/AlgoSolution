class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        int i = 0, j = (int)a.size() - 1;
        while (i <= j && a[i] == nums[i]) {
            ++i;
        }
        while (i <= j && a[j] == nums[j]) {
            --j;
        }
        return j - i + 1;
    }
};
