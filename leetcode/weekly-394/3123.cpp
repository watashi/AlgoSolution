
class Solution {
  static constexpr int64_t INF = 1000000007LL * 1000000007LL;

  template<typename T = int>
  using Graph = vector<vector<pair<int, T>>>;

  template<bool WEIGHTED = false>
  Graph<int64_t> fromEdgeList(int n, const vector<vector<int>>& edges) {
    if (!WEIGHTED && !edges.empty() && edges.front().size() > 2) {
      return fromEdgeList<!WEIGHTED>(n, edges);
    }
    Graph<int64_t> g(n);
    for (const auto& e : edges) {
      int a = e[0], b = e[1], c = WEIGHTED ? e[2] : 1;
      g[a].emplace_back(b, c);
      g[b].emplace_back(a, c);
    }
    return g;
  }

  template<typename T = int>
  pair<vector<T>, vector<int>> minDist(int n, const Graph<T>& e, int s) {
    vector<T> d(n, INF);
    vector<int> pre(n, -1);
    priority_queue<pair<T, int>> pq;
    d[s] = 0;
    pq.emplace(-d[s], s);
    while (!pq.empty()) {
      int a = pq.top().second;
      int da = -pq.top().first;
      pq.pop();
      if (da > d[a]) {
        continue;
      }
      for (auto i : e[a]) {
        int b = i.first;
        int db = da + i.second;
        if (db < d[b]) {
          d[b] = db;
          pre[b] = a;
          pq.emplace(-d[b], b);
        }
      }
    }
    return make_pair(d, pre);
  }

public:
  vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    const auto g = fromEdgeList<true>(n, edges);
    auto ds = minDist<int64_t>(n, g, 0);
    auto dt = minDist<int64_t>(n, g, n - 1);

    vector<bool> ret;
    for (const auto& e : edges) {
      int a = e[0], b = e[1], c = e[2];
      // cout << ds.first[a] << " " << dt.first[b] << " " << c << endl;
      auto ok = ds.first[a] + dt.first[b] + c == dt.first[0];
      if (!ok) {
        swap(a, b);
        ok = ds.first[a] + dt.first[b] + c == dt.first[0];
      }
      ret.push_back(ok);
    }
    return ret;
  }
};
