#include <set>
#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

map<int, int> from, to;
int r, c, add, sub;

void insert(int s, int t) {
  from[s] = t;
  to[t] = s;
  add += max(0, (t - s) - sub);
}

void erase(int s, int t) {
  from.erase(s);
  to.erase(t);
  add -= max(0, (t - s) - sub);
}

void insert(int x) {
  int l = x, r = x + 1;
  if (from.count(x + 1)) {
    r = from[x + 1];
    erase(x + 1, r);
  }
  if (to.count(x)) {
    l = to[x];
    erase(l, x);
  }
  insert(l, r);
}

void erase(int x) {
  int l = to.upper_bound(x)->second;
  int r = from[l];
  erase(l, r);
  if (l < x) {
    insert(l, x);
  }
  if (x + 1 < r) {
    insert(x + 1, r);
  }
}

void init(int w, int h, int p, int q) {
  r = h;
  c = w;
  add = 0;
  sub = p - 1;
  (void)q;
  from.clear();
  to.clear();
  insert(0, w);
}

set<int> x[MAXN], y[MAXN];

int main() {
  int re, w, h, p, q, n, x, y, a, b, c, d;
  long long ans;

  scanf("%d", &re);
  for (int ri = 1; ri <= re; ++ri) {
    scanf("%d%d%d%d%d%d%d%d%d%d%d", &w, &h, &p, &q, &n, &x, &y, &a, &b, &c, &d);
    for (int i = 0; i < h; ++i) {
      ::x[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      ::x[y].insert(x);
      long long xx = x;
      long long yy = y;
      x = (xx * a + yy * b + 1) % w;
      y = (xx * c + yy * d + 1) % h;
    }

    ans = 0;
    init(w, h, p, q);
    for (int i = 0; i < w; ++i) {
      ::y[i].clear();
    }
    for (int i = 0; i < h; ++i) {
      for (int j: ::x[i]) {
        if (::y[j].empty()) {
          erase(j);
        }
        ::y[j].insert(i);
      }
      if (i >= q) {
        for (int j: ::x[i - q]) {
          ::y[j].erase(i - q);
          if (::y[j].empty()) {
            insert(j);
          }
        }
      }
      if (i >= q - 1) {
        ans += add;
      }
    }
    printf("Case #%d: %lld\n", ri, ans);
  }

  return 0;
}

