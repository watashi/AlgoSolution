class Solution {
public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    set<int> st(nums.begin(), nums.end());
    int ret = 0;
    for (int i : nums) {
      if (st.count(i - diff) > 0 && st.count(i + diff) > 0) {
        ++ret;
      }
    }
    return ret;
  }
};
