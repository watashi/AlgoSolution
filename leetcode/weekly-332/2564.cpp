class Solution {
public:
  vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
    unordered_map<int64_t, pair<int, int>> m;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
      int64_t k = s[i] - '0';
      if (m.count(k) == 0) {
        m[k] = make_pair(0, i);
      }
      if (k == 0) {
        continue;
      }
      for (int j = 1; j < 32 && i + j < n; ++j) {
        k <<= 1;
        k ^= s[i + j] - '0';
        if (m.count(k) == 0) {
          m[k] = make_pair(j, i);
        }
        else {
          auto& v = m[k];
          v = min(v, make_pair(j, i));
        }
      }
    }
    vector<vector<int>> ret;
    for (const auto& q : queries) {
      int64_t k = q[0] ^ q[1];
      auto it = m.find(k);
      if (it == m.end()) {
        ret.push_back({-1, -1});
      }
      else {
        ret.push_back({ it->second.second, it->second.second + it->second.first });
      }
    }
    return ret;
  }
};
