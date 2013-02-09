#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 30000;

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

vector<pair<int, int> > edge;

int main() {
  int re, n, m, k, a, b;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d", &n, &m, &k);
    ds.init(n);
    edge.clear();

    for (int i = 0; i < m; ++i) {
      scanf("%d%d", &a, &b);
      if (a >= k && b >= k) {
        ds.setp(a, b);
      } else {
        edge.push_back({a, b});
      }
    }

    int ans = 0;
    for (auto e: edge) {
      if (!ds.setp(e.first, e.second)) {
        ++ans;
      }
    }

    printf("Case #%d: ", ri);
    printf("%d\n", ans);
    fflush(stdout);
  }

  return 0;
}
