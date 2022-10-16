class Solution {
public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> st;
    for (int i : nums) {
      st.insert(i);
      int j = 0;
      while (i > 0) {
        j = j * 10 + i % 10;
        i /= 10;
      }
      st.insert(j);
    }
    return st.size();
  }
};
