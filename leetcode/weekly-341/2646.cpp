class Solution {
public:
  vector<vector<int>> e;
  vector<vector<int>> ps;
  vector<int> sav;

  void dfs(int v, int p) {
    ps[v].push_back(v);
    for (int w : e[v]) {
      if (w != p) {
        ps[w] = ps[v];
        dfs(w, v);
      }
    }
  }

  pair<int, int> dfs2(int v, int p) {
    pair<int, int> ret(0, sav[v]);
    for (int w : e[v]) {
      if (w != p) {
        auto tmp = dfs2(w, v);
        ret.first += max(tmp.first, tmp.second);
        ret.second += tmp.first;
      }
    }
    return ret;
  }

  int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
    e.clear();
    e.resize(n);
    for (const auto& i : edges) {
      int a = i[0], b = i[1];
      e[a].push_back(b);
      e[b].push_back(a);
    }
    ps.clear();
    ps.resize(n);
    dfs(0, -1);
    for (auto& p : ps) {
      reverse(p.begin(), p.end());
    }

    map<int, int> mp;
    for (const auto& i : trips) {
      int a = i[0], b = i[1];
      auto pa = ps[a], pb = ps[b];
      int lca = pa.back();
      while (!pa.empty() && !pb.empty() && pa.back() == pb.back()) {
        lca = pa.back();
        pa.pop_back();
        pb.pop_back();
      }
      pa.push_back(lca);
      pa.insert(pa.end(), pb.rbegin(), pb.rend());

      for (auto v : pa) {
        ++mp[v];
      }
    }

    int tot = 0;
    sav.clear();
    sav.resize(n);
    for (const auto& i : mp) {
      auto k = i.first, v = i.second, p = price[k];
      tot += p * v;
      sav[k] = (p + 1) / 2 * v;
    }
    pair<int, int> ret = dfs2(0, -1);
    tot -= max(ret.first, ret.second);
    return tot;
  }
};
