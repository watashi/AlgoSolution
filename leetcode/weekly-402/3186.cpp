class Solution {
public:
  long long maximumTotalDamage(vector<int>& power) {
    map<int, long long> mp;
    for (int i : power) {
      mp[i] += i;
    }
    vector<pair<int, long long>> v(mp.begin(), mp.end());
    const int n = v.size();
    vector<long long> dp(n, 0);
    dp[0] = v[0].second;
    for (int i = 1; i < n; ++i) {
      dp[i] = max(v[i].second, dp[i - 1]);
      for (int j = i - 1; j >= 0; --j) {
        if (v[j].first < v[i].first - 2) {
          dp[i] = max(dp[i], dp[j] + v[i].second);
          break;
        }
      }
    }
    return dp.back();
  }
};
