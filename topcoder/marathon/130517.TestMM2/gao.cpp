#include <map>
#include <cmath>
#include <ctime>
#include <limits>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <cassert>
#include <sstream>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))

typedef long long llint;

namespace timer {
  const llint MSEC_PER_SEC = 1000000LL;
  const llint TIME_LIMIT = 19500000;

  static timeval tv;
  static llint end, now;

  inline void start() {
    gettimeofday(&tv, NULL);
    end = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec + TIME_LIMIT;
  }

  inline bool timeout() {
    gettimeofday(&tv, NULL);
    now = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec;
    return now > end;
  }
}

const int MAXN = 103;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

static char str[MAXN * MAXN];
static int sz, sz2, cc;
static int idx[MAXN][MAXN];
static int ans[MAXN][MAXN];

static bool mark[MAXN][MAXN];

inline bool valid(int x) {
  return 0 <= x && x < sz;
}

inline bool valid(int x, int y) {
  return valid(x) && valid(y);
}

void dfs(int x, int y, char z) {
  if (valid(x, y) && !mark[x][y] && str[idx[x][y]] == z) {
    mark[x][y] = true;
    FOR (k, 4) {
      dfs(x + dx[k], y + dy[k], z);
    }
  }
}

void upd() {
  int m = 0;
  MEMSET(mark, 0);
  FOR (i, sz) {
    FOR (j, sz) {
      if (!mark[i][j]) {
        ++m;
        dfs(i, j, str[idx[i][j]]);
      }
    }
  }
  if (cc > m) {
    cc = m;
    copy(idx[0], idx[sz], ans[0]);
  }
}

void zigzag() {
  FOR (i, sz) {
    FOR (j, sz) {
      idx[i][j] = i * sz + j;
    }
    if (i % 2 != 0) {
      reverse(idx[i], idx[i] + sz);
    }
  }
  upd();
}

void circin() {
  int x = 0, y = 0, z = 0;
  MEMSET(idx, 0xff);
  FOR (i, sz2) {
    idx[x][y] = i;
    FOR (j, 4) {
      int xx = x + dx[z];
      int yy = y + dy[z];
      if (valid(xx, yy) && idx[xx][yy] == -1) {
        x = xx;
        y = yy;
        break;
      } else {
        z = (z + 3) & 3;
      }
    }
  }
  upd();
}

void circout() {
  int x = 0, y = 0, z = 0;
  MEMSET(idx, 0xff);
  FOR (i, sz2) {
    idx[x][y] = sz2 - 1 - i;
    FOR (j, 4) {
      int xx = x + dx[z];
      int yy = y + dy[z];
      if (valid(xx, yy) && idx[xx][yy] == -1) {
        x = xx;
        y = yy;
        break;
      } else {
        z = (z + 3) & 3;
      }
    }
  }
  upd();
}

struct StringConnectivity {
  vector<int> placeString(const string& s) {
    sz2 = (int)s.size();
    sz = (int)nearbyint(sqrt(sz2));
    cc = sz2 + 1;
    copy(ALL(s), str);

    clog << "size    = " << sz << endl;
    clog << "strlen  = " << s.size() << endl;
    clog << "charset = " << *max_element(ALL(s)) - 'a' + 1 << endl;
    zigzag();
    clog << "zigzag  = " << cc << endl;
    circin();
    clog << "circin  = " << cc << endl;
    circout();
    clog << "circout = " << cc << endl;
    clog << "time    = " << (double)clock() / CLOCKS_PER_SEC << endl;

    vector<int> ret;
    FOR (i, sz) {
      FOR (j, sz) {
        if (ans[i][j] == 0) {
          ret.push_back(i);
          ret.push_back(j);
        }
      }
    }
    for (int x = ret[0], y = ret[1]; ans[x][y] != sz2 - 1; ) {
      FOR (k, 4) {
        int xx = x + dx[k];
        int yy = y + dy[k];
        if (ans[xx][yy] == ans[x][y] + 1) {
          ret.push_back(k);
          x = xx;
          y = yy;
          break;
        }
      }
    }
    return ret;
  }
};

#ifdef __WATASHI__
int main() {
  string s;
  vector<int> ret;

  cin >> s;
  ret = StringConnectivity().placeString(s);
  for (int i: ret) {
    cout << i << endl;
  }

  return 0;
}
// vim: ft=cpp.doxygen
#endif
