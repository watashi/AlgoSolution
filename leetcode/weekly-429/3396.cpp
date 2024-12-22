class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    const int n = nums.size();
    unordered_set<int> st;
    for (int i = n - 1; i >= 0; --i) {
      if (!st.insert(nums[i]).second) {
        return i / 3 + 1;
      }
    }
    return 0;
  }
};
