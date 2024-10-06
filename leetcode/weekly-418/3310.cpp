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
    }
    return g;
  }

public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    Graph<int> g = fromEdgeList(n, invocations);
    vector<bool> mark(n, false);
    queue<int> q;
    mark[k] = true;
    q.push(k);
    while (!q.empty()) {
      int from = q.front();
      q.pop();
      for (const auto& e : g[from]) {
        int to = e.first;
        if (!mark[to]) {
          mark[to] = true;
          q.push(to);
        }
      }
    }

    vector<int> ret;
    for (const auto& e : invocations) {
      int from = e[0];
      int to = e[1];
      if (!mark[from] && mark[to]) {
        ret.resize(n);
        iota(ret.begin(), ret.end(), 0);
        return ret;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (!mark[i]) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
