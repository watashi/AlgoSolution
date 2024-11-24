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

public:
  Graph<int> g;
  int k;

  pair<long long, long long> gao(int v, int p) {
    long long base = 0;
    vector<long long> diff;
    for (const auto& i : g[v]) {
      if (i.first == p) {
        continue;
      }
      auto child = gao(i.first, v);
      base += child.second;
      diff.push_back(max(0LL, child.first + i.second - child.second));
    }
    sort(diff.rbegin(), diff.rend());

    if (diff.size() < k) {
      base += accumulate(diff.begin(), diff.end(), 0LL);
      return make_pair(base, base);
    }
    else {
      base += accumulate(diff.begin(), diff.begin() + k - 1, 0LL);
      return make_pair(base, base + diff[k - 1]);
    }
  }

  long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
    const int n = edges.size() + 1;
    this->g = fromEdgeList(n, edges);
    this->k = k;
    auto ret = gao(0, 0);
    return max(ret.first, ret.second);
  }
};
