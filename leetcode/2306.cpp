class Solution {
public:
  long long distinctNames(vector<string>& ideas) {
    static constexpr int CHARSET = 26;
    unordered_map<string, int> mp;
    for (const auto& i : ideas) {
      mp[i.substr(1)] |= 1 << (i[0] - 'a');
    }

    vector<vector<long long>> c(CHARSET, vector<long long>(CHARSET, 0));
    vector<int> x, y;
    x.reserve(CHARSET);
    y.reserve(CHARSET);
    for (const auto& i : mp) {
      x.clear();
      y.clear();
      for (int j = 0; j < CHARSET; ++j) {
        if ((i.second >> j) & 1) {
          x.push_back(j);
        }
        else {
          y.push_back(j);
        }
      }
      for (int xi : x) {
        for (int yi : y) {
          ++c[xi][yi];
        }
      }
    }

    long long ans = 0;
    for (int i = 0; i < CHARSET; ++i) {
      for (int j = 0; j < CHARSET; ++j) {
        ans += c[i][j] * c[j][i];
      }
    }
    return ans;
  }
};
