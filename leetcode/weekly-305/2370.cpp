class Solution {
public:
  int longestIdealString(string s, int k) {
    vector<int> dp(26, 0);
    for (char c : s) {
      int x = c - 'a';
      int y = 0;
      for (int i = 0; i < 26; ++i) {
        if (abs(i - x) <= k) {
          y = max(y, dp[i]);
        }
      }
      dp[x] = y + 1;
    }
    return *max_element(dp.begin(), dp.end());
  }
};
