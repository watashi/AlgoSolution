#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 512;

struct DisjointSet {
  int p[MAXN];

  void init(int n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
    }
  }

  int getp(int i) {
    return i == p[i] ? i : (p[i] = getp(p[i]));
  }

  bool setp(int i, int j) {
    i = getp(i);
    j = getp(j);
    p[i] = j;
    return i != j;
  }
} ds;

vector<pair<int, int> > e;
map<int, DisjointSet> head, tail;
map<pair<int, int>, int> cache;

int gao(int n, DisjointSet a, DisjointSet b) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    a.setp(i, b.getp(i));
  }
  for (int i = 0; i < n; ++i) {
    if (a.getp(i) == i) {
      ++ret;
    }
  }
  return ret;
}

int main() {
  int n, m, a, b;
  map<int, DisjointSet>::const_iterator it, jt;

  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    e.push_back({a, b});
  }

  ds.init(n);
  head[-1] = ds;
  for (int i = 0; i < m; ++i) {
    if (ds.setp(e[i].first, e[i].second)) {
      head[i] = ds;
    }
  }
  ds.init(n);
  tail[m] = ds;
  for (int i = m - 1; i >= 0; --i) {
    if (ds.setp(e[i].first, e[i].second)) {
      tail[i] = ds;
    }
  }

  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    it = head.lower_bound(a);
    --it;
    jt = tail.upper_bound(b);
    if (cache.count({it->first, jt->first}) == 0) {
      cache[{it->first, jt->first}] = gao(n, it->second, jt->second);
    }
    printf("%d\n", cache[{it->first, jt->first}]);
  }
}


