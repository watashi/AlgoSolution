
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

  static constexpr int MAXW = 27;
  static constexpr int MAXB = 15;

  Graph g;

  struct Info {
    int d;
    array<int, MAXB> p;
    valarray<int> c;
  };

  vector<Info> info;

  void dfs(int v) {
    auto& iv = info[v];
    for (int i = 1; i < MAXB; ++i) {
      iv.p[i] = info[iv.p[i - 1]].p[i - 1];
    }
    for (const auto& i : g[v]) {
      int w = i.first;
      if (w != info[v].p[0]) {
        info[w].d = info[v].d + 1;
        info[w].p[0] = v;
        info[w].c = info[v].c;
        ++info[w].c[i.second];
        dfs(w);
      }
    }
  }

  int up(int v, int n) {
    for (int i = 0; n > 0; ++i, n >>= 1) {
      if (n & 1) {
        v = info[v].p[i];
      }
    }
    return v;
  }

  int lca(int a, int b) {
    if (info[a].d < info[b].d) {
      return lca(b, a);
    }

    a = up(a, info[a].d - info[b].d);
    if (a != b) {
      for (int i = MAXB - 1; i >= 0; --i) {
        if (info[a].p[i] != info[b].p[i]) {
          a = info[a].p[i];
          b = info[b].p[i];
        }
      }
      a = info[a].p[0];
    }
    return a;
  }

public:
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    g = fromEdgeList(n, edges);
    info.resize(n);
    info[0].d = 0;
    info[0].p[0] = 0;
    info[0].c = valarray<int>(0, MAXW);
    dfs(0);

    vector<int> ret;
    for (const auto& q : queries) {
      int a = q[0], b = q[1], p = lca(a, b);
      auto c = info[a].c + info[b].c - 2 * info[p].c;
      ret.push_back(c.sum() - c.max());
    }
    return ret;
  }
};

