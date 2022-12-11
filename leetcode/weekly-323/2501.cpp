class Solution {
public:
  int longestSquareStreak(vector<int>& nums) {
    set<int64_t> st(nums.begin(), nums.end());
    int ret = 0;
    while (!st.empty()) {
      int cnt = 1;
      int64_t tmp = *st.begin();
      st.erase(tmp);
      tmp *= tmp;
      while (st.count(tmp) > 0) {
        st.erase(tmp);
        cnt += 1;
        tmp *= tmp;
      }
      ret = max(ret, cnt);
    }
    return ret >= 2 ? ret : -1;
  }
};
