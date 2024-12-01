class Solution {
  template<typename T = int>
  using Graph = vector<vector<pair<int, T>>>;

  template<bool WEIGHTED = false>
  Graph<int> fromEdgeList(int n, const vector<vector<int>>& edges) {
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

  void dfs(int v, int p, Graph<int>& g, vector<vector<pair<int, int>>>& c) {
    c[v][0].first += 1;
    for (const auto& j : g[v]) {
      auto w = j.first;
      if (w == p) {
        continue;
      }
      dfs(w, v, g, c);
      for (int i = 0; i < 2; ++i) {
        c[v][i].first += c[w][i ^ 1].first;
      }
    }
  }

  void gao(int v, int p, Graph<int>& g, vector<vector<pair<int, int>>>& c) {
    if (v != p) {
      for (int i = 0; i < 2; ++i) {
        c[v][i].second += c[p][i ^ 1].second;
        c[v][i].second += c[p][i ^ 1].first - c[v][i].first;
      }
    }
    for (const auto& j : g[v]) {
      auto w = j.first;
      if (w == p) {
        continue;
      }
      gao(w, v, g, c);
    }
  }

public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    const int n1 = edges1.size() + 1;
    const int n2 = edges2.size() + 1;
    Graph<int> g1 = fromEdgeList(n1, edges1);
    Graph<int> g2 = fromEdgeList(n2, edges2);
    vector<vector<pair<int, int>>> c1(n1, vector<pair<int, int>>(2));
    vector<vector<pair<int, int>>> c2(n2, vector<pair<int, int>>(2));
    dfs(0, 0, g1, c1);
    gao(0, 0, g1, c1);
    dfs(0, 0, g2, c2);
    gao(0, 0, g2, c2);
    int add = 0;
    for (int i = 0; i < n2; ++i) {
      for (int j = 0; j < 2; ++j) {
        add = max(add, c2[i][j].first + c2[i][j].second);
      }
    }
    cout << add << endl;
    vector<int> ret(n1);
    for (int i = 0; i < n1; ++i) {
      ret[i] = c1[i][0].first + c1[i][0].second + add;
    }
    return ret;
  }
};
