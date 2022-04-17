class Solution {
public:
  static pair<int, int> dfs(const vector<vector<int>>& e, const string& s, int v) {
    pair<int, int> ret(0, 0);
    vector<int> cs;
    for (int w : e[v]) {
      auto tmp = dfs(e, s, w);
      ret.second = max(ret.second, tmp.second);
      if (s[v] != s[w]) {
        cs.push_back(tmp.first);
      }
    }
    sort(cs.rbegin(), cs.rend());
    ret.first = (cs.size() >= 1 ? cs[0] : 0) + 1;
    ret.second = max(ret.second, ret.first);
    if (cs.size() >= 2) {
      ret.second = max(ret.second, cs[0] + cs[1] + 1);
    }
    return ret;
  }

  int longestPath(vector<int>& parent, string s) {
    int n = parent.size();
    vector<vector<int>> e(n);
    for (int i = 1; i < n; ++i) {
      e[parent[i]].push_back(i);
    }
    auto ret = dfs(e, s, 0);
    return ret.second;
  }
};
