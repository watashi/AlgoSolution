class Solution {
public:
  struct Worker {
    int l2r, pold, r2l, pnew;
    pair<int, int> p;

    Worker(int id, const vector<int>& v): l2r(v[0]), pold(v[1]), r2l(v[2]), pnew(v[3]), p(l2r + r2l, id) {

    }

    bool operator<(const Worker& o) const {
      return p < o.p;
    }
  };

  template<typename T> T spop(set<T>& st) {
    auto ret = *st.begin();
    st.erase(st.begin());
    return ret;
  }

  void unpending(int cur, set<pair<int, int>>& p, set<int>& w) {
    while (!p.empty() && p.begin()->first <= cur) {
      w.insert(spop(p).second);
    }
  }

  int findCrossingTime(int n, int k, vector<vector<int>>& time) {
    vector<Worker> ws;
    ws.reserve(time.size());
    for (int i = 0; i < time.size(); ++i) {
      ws.emplace_back(i, time[i]);
    }
    sort(ws.rbegin(), ws.rend());

    set<pair<int, int>> pl, pr;
    set<int> wl, wr;
    for (int i = 0; i < k; ++i) {
      wl.insert(i);
    }
    int cur = 0;
    int ret = 0;
    while (n > 0 || !pr.empty() || !wr.empty()) {
      unpending(cur, pl, wl);
      unpending(cur, pr, wr);
      if (!wr.empty()) {
        auto x = spop(wr);
        cur += ws[x].r2l;
        ret = max(cur, ret);
        pl.emplace(cur + ws[x].pnew, x);
      }
      else if (!wl.empty() && n > 0) {
        auto x = spop(wl);
        cur += ws[x].l2r;
        pr.emplace(cur + ws[x].pold, x);
        --n;
      }
      else if (pl.empty()) {
        cur = pr.begin()->first;
      }
      else if (pr.empty()) {
        cur = pl.begin()->first;
      }
      else {
        cur = min(pl.begin()->first, pr.begin()->first);
      }
    }
    return ret;
  }
};
