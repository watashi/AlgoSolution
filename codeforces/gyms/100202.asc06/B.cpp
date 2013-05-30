#include <set>
#include <cstdio>
#include <cstdlib>
#include <utility>
//#include <ext/hash_set>

using namespace std;
/*
using namespace __gnu_cxx;

namespace __gnu_cxx {
  template<>
  struct hash<pair<int, int> > {
    size_t operator()(const pair<int, int>& val) const {
      return (val.first * val.second) ^ (val.first + val.second);
    }
  };
}
*/
void add(int x, int y, int d, set<pair<int, int> >& s) {
  d += 2;
  for (int i = -d + 1; i < d; ++i) {
    for (int j = -d + 1; j < d; ++j) {
      if (abs(i) + abs(j) <= d) {
        s.insert(make_pair(x + i, y + j));
      }
    }
  }
}

int main() {
  bool b;
  int n, x, y, c;
  pair<int, int> p;
  set<pair<int, int> > s, q;

#ifndef __WATASHI__
  freopen("control.in", "r", stdin);
  freopen("control.out", "w", stdout);
#endif
  scanf("%d", &n);
  s.clear();
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &y, &c);
    add(x, y, c, s);
  }
  q.clear();
  for (set<pair<int, int> >::const_iterator it = s.begin(); it != s.end(); ++it) {
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        p = make_pair(it->first + i, it->second + j);
        if (s.count(p) == 0) {
          q.insert(p);
        }
      }
    }
  }

  while (!q.empty()) {
    p = *q.begin();
    q.erase(q.begin());
    b = true;
    for (int i = p.first - 1; b && i <= p.first; ++i) {
      for (int j = p.second - 1; b && j <= p.second; ++j) {
        b &= s.count(make_pair(i, j)) != 0 ||
          s.count(make_pair(i, j + 1)) != 0 ||
          s.count(make_pair(i + 1, j)) != 0 ||
          s.count(make_pair(i + 1, j + 1)) != 0;
      }
    }
    if (b) {
      s.insert(p);
      for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
          if (s.count(make_pair(p.first + i, p.second + j)) == 0) {
            q.insert(make_pair(p.first + i, p.second + j));
          }
        }
      }
    }
  }

  printf("%d\n", (int)s.size());

  return 0;
}

