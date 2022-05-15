class Solution {
public:
  int largestCombination(vector<int>& candidates) {
    int ans = 0;
    for (int i = 0; i < 32; ++i) {
      int cnt = 0;
      for (int j : candidates) {
        if ((j & (1 << i)) != 0) {
          ++cnt;
        }
      }
      ans = max(ans, cnt);
    }
    return ans;
  }
};
