class Solution {
  struct PrimeTable {
    vector<int> p;

    void init(int n) {
      p = vector<int>(n, 0);
      iota(p.begin(), p.end(), 0);
      for (int i = 2; i * i < n; ++i) {
        if (p[i] == i) {
          for (int j = i * i; j < n; j += i) {
            if (p[j] == j) {
              p[j] = i;
            }
          }
        }
      }
    }
  };

  PrimeTable pt;

  using Graph = vector<vector<pair<int, int>>>;

  template<bool WEIGHTED = false>
  Graph fromEdgeList(int n, const vector<vector<int>>& edges) {
    if (!WEIGHTED && !edges.empty() && edges.front().size() > 2) {
      return fromEdgeList<!WEIGHTED>(n, edges);
    }
    Graph g(n);
    for (const auto& e : edges) {
      int a = e[0] - 1, b = e[1] - 1, c = WEIGHTED ? e[2] : 1;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    return g;
  }

  Graph g;
  vector<int> par, root;
  vector<long long> cnt;

  bool isp(int i) const {
    ++i;
    return i >= 2 && pt.p[i] == i;
  }

  void dfs(int v, int p) {
    cnt[v] = isp(v) ? 0 : 1;
    for (const auto& i : g[v]) {
      int w = i.first;
      if (w == p) {
        continue;
      }
      par[w] = v;
      root[w] = isp(v) ? w : root[v];
      dfs(w, v);
      if (!isp(w)) {
        cnt[v] += cnt[w];
      }
    }
  }

public:
  long long countPaths(int n, vector<vector<int>>& edges) {
    pt.init(n + 1);
    g = fromEdgeList(n, edges);
    par = root = vector<int>(n, 0);
    cnt = vector<long long>(n, 0);
    par[0] = root[0] = 0;
    dfs(0, 0);

    long long ret = 0;
    for (int i = 0; i < n; ++i) {
      if (!isp(i)) {
        continue;
      }
      long long tot = 0;
      for (const auto& jj : g[i]) {
        int j = jj.first;
        long long k = 0;
        if (!isp(j)) {
          k = j == par[i] ? cnt[root[i]] : cnt[j];
        }
        // printf("[%d,%d] %lld\n", i + 1, j + 1, k);
        tot += k;
        ret -= k * (k - 1) / 2;
      }
      ret += tot * (tot - 1) / 2 + tot;
    }
    return ret;
  }
};
