class Solution {
public:
  template<typename T = int>
  using Graph = vector<vector<pair<int, T>>>;

  template<bool WEIGHTED = false>
  static Graph<int> fromEdgeList(int n, const vector<vector<int>>& edges) {
    if (!WEIGHTED && !edges.empty() && edges.front().size() > 2) {
      return fromEdgeList<!WEIGHTED>(n, edges);
    }
    Graph<int> g(n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1], c = WEIGHTED ? e[2] : 1;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    return g;
  }

  static void dfs(const Graph<int>& g, vector<int>& d, int v) {
    for (const auto& w : g[v]) {
      if (d[w.first] == -1) {
        d[w.first] = d[v] + 1;
        dfs(g, d, w.first);
      }
    }
  }

  static int longestPath(const vector<vector<int>>& edges) {
    const int n = (int)edges.size() + 1;
    const auto g = fromEdgeList(n, edges);
    vector<int> d(n, -1);
    d[0] = 0;
    dfs(g, d, 0);
    int v = max_element(d.begin(), d.end()) - d.begin();
    d = vector<int>(n, -1);
    d[v] = 0;
    dfs(g, d, v);
    return *max_element(d.begin(), d.end());
  }

  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    int d1 = longestPath(edges1), d2 = longestPath(edges2);
    return max({ d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1 });
  }
};
