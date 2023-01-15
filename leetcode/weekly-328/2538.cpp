class Solution {
public:
  vector<int> cost;
  vector<vector<int>> e;
  vector<vector<pair<int64_t, int>>> c;

  int dfs(int v, int p) {
    c[v].emplace_back(0, -1);
    for (int w : e[v]) {
      if (w != p) {
        c[v].emplace_back(dfs(w, v), w);
      }
    }
    sort(c[v].rbegin(), c[v].rend());
    if (c[v].size() > 2) {
      c[v].resize(2);
    }
    return c[v][0].first + cost[v];
  }

  int64_t gao(int v, int p, int64_t cp) {
    int64_t ret = cp;
    ret = max(ret, c[v][0].first);
    cp += cost[v];
    for (int w : e[v]) {
      if (w != p) {
        int64_t cp2 = cp;
        if (w == c[v][0].second) {
          cp2 = max(cp2, c[v][1].first + cost[v]);
        }
        else {
          cp2 = max(cp2, c[v][0].first + cost[v]);
        }
        ret = max(ret, gao(w, v, cp2));
      }
    }
    return ret;
  }

  long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
    cost = price;
    e.clear();
    e.resize(n);
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[a].push_back(b);
      e[b].push_back(a);
    }
    c.clear();
    c.resize(n);
    dfs(0, 0);
    return gao(0, 0, 0);
  }
};
