class Solution {
public:
  int findMaxK(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());
    int ret = -1;
    for (int i : nums) {
      if (i > 0 && st.count(-i) > 0) {
        ret = max(ret, i);
      }
    }
    return ret;
  }
};
