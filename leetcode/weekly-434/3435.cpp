class Solution {
public:
  vector<vector<int>> supersequences(vector<string>& words) {
    vector<int> mp(26, -1);
    vector<int> chars;
    for (const string& s : words) {
      for (char c : s) {
        auto i = c - 'a';
        if (mp[i] == -1) {
          mp[i] = chars.size();
          chars.push_back(i);
        }
      }
    }

    int n = chars.size();
    vector<int> lt(n, 0);
    for (const string& s : words) {
      int a = mp[s[0] - 'a'], b = mp[s[1] - 'a'];
      lt[b] |= 1 << a;
    }

    int best = 0;
    vector<int> dp(1 << n, -1);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
      if (dp[i] == -1) {
        continue;
      }
      for (int j = 0; j < n; ++j) {
        int k = i ^ (1 << j);
        if (k > i && (lt[j] & k) == 0) {
          dp[k] = dp[i] + 1;
          best = max(best, dp[k]);
        }
      }
    }

    vector<int> base(26, 0);
    for (char c : chars) {
      base[c] = 2;
    }
    vector<vector<int>> ret;
    for (int i = 0; i < (1 << n); ++i) {
      if (dp[i] == best) {
        for (int j = 0; j < n; ++j) {
          if ((i >> j) & 1) {
            --base[chars[j]];
          }
        }
        ret.push_back(base);
        for (int j = 0; j < n; ++j) {
          if ((i >> j) & 1) {
            ++base[chars[j]];
          }
        }
      }
    }
    return ret;
  }
};
