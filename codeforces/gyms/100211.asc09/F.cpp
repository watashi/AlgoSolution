#include <list>
#include <cstdio>
#include <limits>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

const int MAXN = 512;

template<typename T>
inline T succ(T value) {
  return ++value;
}

vector<pair<int, int> > e[MAXN];
int d[MAXN], s;

void dfs(int x, int y) {
  d[x] = y;
  for (int i = 0; i < (int)e[x].size(); ++i) {
    if (d[e[x][i].first] == -1) {
      dfs(e[x][i].first, y + e[x][i].second);
    }
  }
}

bool ok(int n, int m, const int d[MAXN][MAXN]) {
  for (int i = 0; i < n; ++i) {
    if ((int)e[i].size() > 1) {
      return false;
    }
    fill(::d, ::d + m, -1);
    dfs(i, 0);
    for (int j = 0; j < n; ++j) {
      if (d[i][j] != ::d[j]) {
        return false;
      }
    }
  }
  return true;
}

void add(int a, int b, int c) {
  // printf("%d %d %d\n", a, b, c);
  if (c <= 0) {
    throw 1;
  }
  s += c;
  e[a].push_back(make_pair(b, c));
  e[b].push_back(make_pair(a, c));
}

int main() {
  int n, m, x, y, t;
  int d[MAXN][MAXN];
  list<int> v;

#ifndef __WATASHI__
  freopen("restore.in", "r", stdin);
  freopen("restore.out", "w", stdout);
#endif
  scanf("%d", &n);
  v.clear();
  m = n;
  for (int i = 0; i < n; ++i) {
    e[i].clear();
    v.push_back(i);
    for (int j = 0; j < n; ++j) {
      scanf("%d", &d[i][j]);
    }
  }

  try {
    s = 0;
    while (v.size() > 2) {
      // find leaf
      x = v.front();
      t = d[v.front()][v.back()];
      for (list<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        for (list<int>::const_iterator j = succ(i); j != v.end(); ++j) {
          if (t < d[*i][*j]) {
            t = d[*i][*j];
            x = *i;
          }
        }
      }

      // find length
      t = numeric_limits<int>::max();
      for (list<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        for (list<int>::const_iterator j = succ(i); j != v.end(); ++j) {
          if (*i != x && *j != x && t > d[*i][x] + d[*j][x] - d[*i][*j]) {
            t = d[*i][x] + d[*j][x] - d[*i][*j];
          }
        }
      }
      if (t % 2 != 0) {
        throw 1;
      } else {
        t /= 2;
      }

      // find parent
      y = m;
      for (list<int>::iterator i = v.begin(); i != v.end(); ++i) {
        d[*i][m] = d[m][*i] = d[*i][x] - t;
        if (d[*i][m] == 0) {
          y = *i;
          break;
        }
      }
      if (y == m) {
        e[m].clear();
        v.push_back(m++);
      }
      add(x, y, t);
      v.erase(find(v.begin(), v.end(), x));
    }

    if (v.size() > 1) {
      add(v.front(), v.back(), d[v.front()][v.back()]);
    }
    if (!ok(n, m, d)) {
      throw 1;
    }

    printf("%d\n", s + 1);
    n = m;
    for (int i = 0; i < m; ++i) {
      for (vector<pair<int, int> >::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
        if (i < j->first) {
          for (int k = 0; k < j->second; ++k) {
            printf("%d %d\n",
              k == 0 ? i + 1 : n + k,
              k == j->second - 1 ? j->first + 1 : n + k + 1);
          }
          n += j->second - 1;
        }
      }
    }
  } catch (...) {
    puts("-1");
  }

  return 0;
}


