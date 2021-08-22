class Solution {
public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    static constexpr int MAXN = 5000;
    bitset<MAXN> x;
    x[0] = true;
    for (const auto& i: mat) {
      bitset<MAXN> y;
      for (auto j: i) {
        y |= x << j;
      }
      x = y;
    }
    int ans = MAXN;
    for (int i = 0; i < MAXN; ++i) {
      if (x[i]) {
        ans = min(ans, abs(i - target));
      }
    }
    return ans;
  }
};
