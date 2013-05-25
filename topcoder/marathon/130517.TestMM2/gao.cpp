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
  const llint TIME_LIMIT = 19000000;

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

struct DisjointSet {
  int p[MAXN + MAXN];

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
};

struct Solution {
  vector<int> path;
  int orig, left, right, fullcc, halfcc;
  int p[MAXN];
  char s[MAXN];

  int hash() const {
    int ret = (fullcc + 7) * (halfcc + 97);
    FOR (i, sz) {
      ret = ret * 9 + (p[i] + 1) * (s[i] - '0');
    }
    return ret;
  }

  template<int DY, int DZ>
  int filln(int n, int y, int z) {
    FOR (i, n) {
      s[y] = str[z];
      y += DY;
      z += DZ;
      if (DZ == 1 && z == sz2) {
        z = 0;
      }
      if (DZ == -1 && z == -1) {
        z = sz2 - 1;
      }
    }
    return z;
  }

  void calc(const int p0[MAXN], const char s0[MAXN], int fullcc0) {
    static DisjointSet ds;
    ds.init(sz + sz);
    FOR (i, sz) {
      ds.p[i] = p0[i];
    }
    FOR (i, sz) {
      if (s[i] == s0[i]) {
        ds.setp(sz + i, i);
      }
      if (i > 0 && s[i] == s[i - 1]) {
        ds.setp(sz + i, sz + i - 1);
      }
    }

    static int id[MAXN + MAXN];
    MEMSET(id, 0xff);
    fullcc = fullcc0;
    halfcc = 0;
    FOR (i, sz) {
      int j = ds.getp(sz + i);
      if (id[j] == -1) {
        id[j] = i;
        ++halfcc;
      }
      p[i] = id[j];
    }
    FOR (i, sz) {
      int j = ds.getp(i);
      if (id[j] == -1) {
        id[j] = i;
        ++fullcc;
      }
    }
  }
};

template<int DY, int DZ>
int filln(int n, int* y, int z) {
  FOR (i, n) {
    *y = z;
    y += DY;
    z += DZ;
    if (DZ == 1 && z == sz2) {
      z = 0;
    }
    if (DZ == -1 && z == -1) {
      z = sz2 - 1;
    }
  }
  return z;
}

const int P0[MAXN] = {0};
const char S0[MAXN] = {0};

typedef map<pair<int, int>, Solution*> Candidates;

inline void insert(const Solution& sol, int limit, Candidates& mp) {
  int score = 2 * sol.fullcc + sol.halfcc; // TODO: different coefficient based on $charset$
  int hash = sol.hash();
  pair<int, int> key(-score, hash);
  if (mp.count(key) == 0) {
    if ((int)mp.size() < limit) {
      mp[key] = new Solution(sol);
    } else if (mp.begin()->first < key) {
      delete mp.begin()->second;
      mp.erase(mp.begin());
      mp[key] = new Solution(sol);
    }
  }
}

// O(sz^3*limit)
void beam(int limit) {
  // first
  Candidates mp;
  if (sz % 2 != 0) {
    // close
    Solution sol;
    sol.orig = 0;
    sol.path.resize(1);
    for (int i = 1; i < sz; ++i) {
      sol.path[0] = i;
      sol.left = sol.filln<1, 1>(i, 0, 0);
      sol.right = sol.filln<-1, -1>(sz - i, sz - 1, sz2 - 1);
      sol.calc(P0, S0, -1);
      insert(sol, limit, mp);
    }
  } else {
    // open
    Solution sol;
    sol.path.push_back(-1);
    for (int i = 0; i < sz2; ++i) {
      sol.orig = i;
      sol.left = (i + 1) % sz2;
      sol.right = sol.filln<1, -1>(sz, 0, i);
      sol.calc(P0, S0, -1);
      insert(sol, limit, mp);
    }
  }

  // beam
  for (int row = 1; row < sz - 1; ++row) {
    Candidates todo;
    FOREACH (i, mp) {
      const Solution& pre = *i->second;
      if (timer::timeout()) {
        // TODO: mem leak
        if (row == sz - 2) {
          break;
        } else {
          return;
        }
      }
      if ((sz - row) % 2 != 0) {
        // close |-><-|
        Solution sol;
        sol.orig = pre.orig;
        sol.path = pre.path;
        for (int i = 1; i < sz; ++i) {
          sol.path.push_back(i);
          sol.left = sol.filln<1, 1>(i, 0, pre.left);
          sol.right = sol.filln<-1, -1>(sz - i, sz - 1, pre.right);
          sol.calc(pre.p, pre.s, pre.fullcc);
          insert(sol, limit, todo);
          sol.path.pop_back();
        }
      } else {
        // open <-||->
        Solution sol = pre;
        int sep = pre.path.back();
        sol.path.push_back(-1);
        sol.left = sol.filln<-1, 1>(sep, sep - 1, pre.left);
        sol.right = sol.filln<1, -1>(sz - sep, sep, pre.right);
        sol.calc(pre.p, pre.s, pre.fullcc);
        insert(sol, limit, todo);
      }
      delete i->second;
    }
    mp.swap(todo);
  }

  // last
  Solution ret;
  ret.fullcc = cc;
  FOREACH (i, mp) {
    // close
    const Solution& pre = *i->second;
    Solution sol = pre;
    sol.path.push_back(sz);
    sol.left = sol.filln<1, 1>(sz, 0, pre.left);
    sol.right = sol.filln<-1, -1>(0, sz - 1, pre.right);
    sol.calc(pre.p, pre.s, pre.fullcc);
    sol.fullcc += sol.halfcc;
    if (ret.fullcc > sol.fullcc) {
      ret = sol;
    }
    delete i->second;
  }

  // upd
  if (cc > ret.fullcc) {
    int left, right;
    if (sz % 2 != 0) {
      left = 0;
      right = sz2 - 1;
    } else {
      left = (ret.orig + 1) % sz2;
      right = ret.orig;
    }
    FOR (row, sz) {
      if (ret.path[row] != -1) {
        // close
        int sep = ret.path[row];
        left = filln<1, 1>(sep, idx[row], left);
        right = filln<-1, -1>(sz - sep, idx[row] + sz - 1, right);
      } else {
        // open
        int sep = row > 0 ? ret.path[row - 1] : 0;
        left = filln<-1, 1>(sep, idx[row] + sep - 1, left);
        right = filln<1, -1>(sz - sep, idx[row] + sep, right);
      }
    }
    upd();
#ifdef __WATASHI__
    assert(cc == ret.fullcc);
#endif
  }
}

struct StringConnectivity {
  vector<int> placeString(const string& s) {
    timer::start();

    sz2 = (int)s.size();
    sz = (int)nearbyint(sqrt(sz2));
    cc = sz2 + 1;
    copy(ALL(s), str);
    FOR (i, sz2) {
      str[i] = str[i] - 'a' + '1';
    }

    clog << "size    = " << sz << endl;
    clog << "strlen  = " << s.size() << endl;
    clog << "charset = " << *max_element(str, str + sz2) << endl;
    zigzag();
    clog << "zigzag  = " << cc << endl;
    circin();
    clog << "circin  = " << cc << endl;
    circout();
    clog << "circout = " << cc << endl;

    for (int i = sz; !timer::timeout(); i <<= 1) {
      beam(i);
      clog << "beam[" << i << "] = " << cc << endl;
    }
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
