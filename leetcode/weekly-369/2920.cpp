class Solution {

  using Graph = vector<vector<pair<int, int>>>;

  template<bool WEIGHTED = false>
  Graph fromEdgeList(int n, const vector<vector<int>>& edges) {
    if (!WEIGHTED && !edges.empty() && edges.front().size() > 2) {
      return fromEdgeList<!WEIGHTED>(n, edges);
    }
    Graph g(n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1], c = WEIGHTED ? e[2] : 1;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    return g;
  }

  static constexpr int MAXB = 20;
  Graph g;
  vector<int> coins;
  int k;

  vector<int> dfs(int v, int p) {
    vector<int> ret(MAXB, 0);
    for (const auto& e : g[v]) {
      int w = e.first;
      if (w == p) {
        continue;
      }
      auto tmp = dfs(w, v);
      for (int i = 0; i < MAXB; ++i) {
        ret[i] += tmp[i];
      }
    }
    int cv = coins[v];
    for (int i = 0; i < MAXB - 1; ++i) {
      ret[i] = max(ret[i] + cv - k, ret[i + 1] + cv / 2);
      cv >>= 1;
    }
    return ret;
  }
  
public:
  int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
    int n = coins.size();
    this->g = fromEdgeList(n, edges);
    this->coins = coins;
    this->k = k;
    auto dp = dfs(0, 0);
    return dp[0];
  }
};
