class Solution {
public:
  static constexpr int CHARSET = 26;
  static constexpr int64_t INF = 1000000007;

  long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
    vector<vector<int64_t>> d(CHARSET, vector<int64_t>(CHARSET, INF));
    for (int i = 0; i < (int)cost.size(); ++i) {
      int a = original[i] - 'a', b = changed[i] - 'a', c = cost[i];
      d[a][b] = min<int64_t>(d[a][b], c);
    }
    for (int i = 0; i < CHARSET; ++i) {
      d[i][i] = 0;
    }
    for (int k = 0; k < CHARSET; ++k) {
      for (int i = 0; i < CHARSET; ++i) {
        for (int j = 0; j < CHARSET; ++j) {
          d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
      }
    }
    long long ret = 0;
    for (int i = 0; i < (int)source.size(); ++i) {
      auto c = d[source[i] - 'a'][target[i] - 'a'];
      if (c >= INF) {
        return -1;
      }
      ret += c;
    }
    return ret;
  }
};
