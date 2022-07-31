class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    set<int> st(nums.begin(), nums.end());
    st.erase(0);
    return st.size();
  }
};
