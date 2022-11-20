class Solution {
public:
  vector<vector<int>> e;
  int64_t cap;

  pair<int64_t, int64_t> dfs(int v, int p) {
    pair<int64_t, int64_t> ret(1, 0);
    for (int w : e[v]) {
      if (w == p) {
        continue;
      }
      auto tmp = dfs(w, v);
      ret.first += tmp.first;
      ret.second += tmp.second + (tmp.first + cap - 1) / cap;
    }
    return ret;
  }

  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    e.clear();
    e.resize(roads.size() + 1);
    for (const auto& i : roads) {
      int a = i[0], b = i[1];
      e[a].push_back(b);
      e[b].push_back(a);
    }
    cap = seats;
    return dfs(0, 0).second;
  }
};
