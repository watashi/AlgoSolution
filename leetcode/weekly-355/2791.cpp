class Solution {
public:
  using Count = pair<int, unordered_map<int, int>>;
  static constexpr int CHARSET = 26;

  long long merge(Count& from, Count& to) {
    if (from.second.size() > to.second.size()) {
      swap(from, to);
    }
    int m = from.first ^ to.first;
    long long ret = 0;
    for (const auto& i : from.second) {
      long long v = to.second[m ^ i.first];
      if (v > 0) {
        ret += (long long)v * i.second;
      }
      for (int j = 0; j < CHARSET; ++j) {
        auto it = to.second.find(m ^ i.first ^ (1 << j));
        if (it != to.second.end()) {
          ret += (long long)it->second * i.second;
        }
      }
    }
    for (const auto& i : from.second) {
      auto& v = to.second[m ^ i.first];
      v += i.second;
    }
    return ret;
  }

  long long countPalindromePaths(vector<int>& par, string s) {
    vector<int> d(par.size(), 0);
    for (int i = 1; i < (int)par.size(); ++i) {
      ++d[par[i]];
    }
    queue<int> q;
    for (int i = 0; i < (int)par.size(); ++i) {
      if (d[i] == 0) {
        q.push(i);
      }
    }

    vector<Count> dp(par.size(), Count(0, { {0, 1} }));
    long long ret = 0;
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      int p = par[c];
      if (p < 0) {
        continue;
      }

      if (--d[p] == 0) {
        q.push(p);
      }
      dp[c].first ^= 1 << (s[c] - 'a');
      ret += merge(dp[c], dp[p]);
    }
    return ret;
  }
};
