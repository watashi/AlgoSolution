static constexpr int64_t MOD = 1000000007;
static constexpr int NP = 10;
static constexpr int P[NP] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

class Solution {
public:
  int squareFreeSubsets(vector<int>& nums) {
    map<int, int> m;
    for (int i : nums) {
      ++m[i];
    }
    vector<int64_t> dp(1 << NP, 0);
    dp[0] = 1;
    for (const auto& i: m) {
      int k = i.first;
      int v = i.second;
      if (k == 1) {
        continue;
      }
      int m = 0;
      for (int j = 0; j < NP; ++j) {
        if (k % P[j] == 0) {
          m ^= 1 << j;
          if (k / P[j] % P[j] == 0) {
            k = 0;
            break;
          }
        }
      }
      if (k == 0) {
        continue;
      }
      for (int j = (1 << NP) - 1; j >= m; --j) {
        if ((j & m) == m) {
          dp[j] = (dp[j] + dp[j ^ m] * v) % MOD;
        }
      }
    }
    auto ret = accumulate(dp.begin(), dp.end(), 0LL) % MOD;
    for (int i = 0; i < m[1]; ++i) {
      ret = ret * 2 % MOD;
    }
    ret = (ret + MOD - 1) % MOD;
    return ret;
  }
};
