class Solution {
public:
  int maxSum(vector<int>& nums) {
    unordered_set<int> st;
    for (int i : nums) {
      if (i > 0) {
        st.insert(i);
      }
    }
    if (st.empty()) {
      return *max_element(nums.begin(), nums.end());
    }
    else {
      return accumulate(st.begin(), st.end(), 0);
    }
  }
};
