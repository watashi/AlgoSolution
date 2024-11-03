#include "bits/stdc++.h"
 
using namespace std;
 
template<typename T = int>
using Graph = vector<vector<pair<int, T>>>;
 
template<typename T = int, T INF>
pair<vector<T>, vector<int>> minDist(int n, const Graph<T>& e, int s) {
  vector<T> d(n, INF);
  vector<int> pre(n, -1);
  priority_queue<pair<T, int>> pq;
  d[s] = 0;
  pq.emplace(-d[s], s);
  while (!pq.empty()) {
    int a = pq.top().second;
    T da = -pq.top().first;
    pq.pop();
    if (da > d[a]) {
      continue;
    }
    for (auto i : e[a]) {
      int b = i.first;
      T db = da + i.second;
      if (db < d[b]) {
        d[b] = db;
        pre[b] = a;
        pq.emplace(-d[b], b);
      }
    }
  }
  return make_pair(d, pre);
}
 
int main() {
  int re;
  scanf("%d", &re);
 
  for (int ri = 1; ri <= re; ++ri) {
    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
 
    vector<vector<pair<int, int64_t>>> e(2 * n);
    for (int i = 0; i < h; ++i) {
      int a;
      scanf("%d", &a);
      --a;
      e[a].emplace_back(n + a, 0);
    }
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      --u;
      --v;
      e[u].emplace_back(v, w);
      e[v].emplace_back(u, w);
      u += n;
      v += n;
      e[u].emplace_back(v, w / 2);
      e[v].emplace_back(u, w / 2);
    }
 
    static constexpr int64_t INF = 1234567890987654321LL;
    const auto ds = minDist<int64_t, INF>(2 * n, e, 0).first;
    const auto dt = minDist<int64_t, INF>(2 * n, e, n - 1).first;
    auto dst = INF;
    for (int i = 0; i < n; ++i) {
      dst = min(dst, max(min(ds[i], ds[n + i]), min(dt[i], dt[n + i])));
    }
    printf("%lld\n", dst < INF ? dst : -1);
  }
 
  return 0;
}

-- 289814829	Nov/03/2024 10:13UTC-8	watashi	2014E - Rendez-vous de Marian et Robin	C++17 (GCC 7-32)	Accepted	655 ms	37500 KB
