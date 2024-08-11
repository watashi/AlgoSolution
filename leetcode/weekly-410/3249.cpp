class Solution {
  vector<vector<int>> e;

  pair<int, int> dfs(int v, int p) const {
    int good = 0;
    int size = 1;
    int subsize = 0;
    for (int w : e[v]) {
      if (w == p) {
        continue;
      }
      auto t = dfs(w, v);
      good += t.first;
      size += t.second;
      if (subsize == 0) {
        subsize = t.second;
      }
      else if (subsize != t.second) {
        subsize = -1;
      }
    }
    if (subsize != -1) {
      ++good;
    }
    return make_pair(good, size);
  }

public:
  int countGoodNodes(vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    e.clear();
    e.resize(n);
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[a].push_back(b);
      e[b].push_back(a);
    }
    return dfs(0, 0).first;
  }
};
