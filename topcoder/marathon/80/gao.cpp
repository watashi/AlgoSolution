#include <cmath>
#include <ctime>
#include <limits>
#include <cstdio>
#include <string>
#include <vector>
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

const llint MSEC_PER_SEC = 1000000LL;

#ifdef __WATASHI__
const llint TIME_LIMIT = 3868686;
#else
const llint TIME_LIMIT = 9500000;
#endif

static timeval tv;
static llint startll, endll;

void startTimer() {
  gettimeofday(&tv, NULL);
  startll = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec + TIME_LIMIT;
}

bool timeout() {
  gettimeofday(&tv, NULL);
  endll = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec;
  return endll > startll;
}

const int MAXN = 105;

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

enum {
  R = 0,
  D = 1,
  U = 2,
  L = 3
};

struct Node {
  Node *p[4];
  int type;
};

typedef pair<Node*, int> Entry;

const Entry NIL(NULL, 0);

static int sz;
static Node cell[MAXN][MAXN];
static vector<Entry> entry;

inline void init(const vector<string>& board) {
  sz = board.size();
  sz = board[0].size();
  FOR (i, sz + 2) {
    FOR (j, sz + 2) {
      if (1 <= i && i <= sz && 1 <= j && j <= sz) {
        cell[i][j].type = board[i - 1][j - 1] == 'R' ? 1 : 2;
      }
      FOR (k, 4) {
        int ii = i + dx[k], jj = j + dy[k];
        if (0 <= ii && ii <= sz + 1 && 0 <= jj && jj <= sz + 1) {
          cell[i][j].p[k] = &cell[ii][jj];
        }
      }
    }
  }
  for (int i = 1; i <= sz; ++i) {
    entry.push_back(make_pair(&cell[0][i], D));
    entry.push_back(make_pair(&cell[i][0], R));
    entry.push_back(make_pair(&cell[sz + 1][i], U));
    entry.push_back(make_pair(&cell[i][sz + 1], L));
  }
}

inline void detach(Node* cur) {
  cur->p[U]->p[D] = cur->p[D];
  cur->p[D]->p[U] = cur->p[U];
  cur->p[L]->p[R] = cur->p[R];
  cur->p[R]->p[L] = cur->p[L];
}

inline void atach(Node* cur) {
  cur->p[U]->p[D] = cur;
  cur->p[D]->p[U] = cur;
  cur->p[L]->p[R] = cur;
  cur->p[R]->p[L] = cur;
}

inline vector<Node*> remove(Node* cur, int dir) {
  vector<Node*> ret;
  while (true) {
    cur = cur->p[dir];
    if (cur->type == 0) {
      break;
    } else {
      detach(cur);
      ret.push_back(cur);
      dir ^= cur->type;
    }
  }
  return ret;
}

inline void restore(const vector<Node*>& v) {
  for (vector<Node*>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
    atach(*it);
  }
}

inline bool greedy(vector<Entry> entry, int limit, vector<Entry>& ret) {
  if (entry.empty()) {
    return true;
  } else if ((int)ret.size() >= limit) {
    return false;
  } else {
    Entry best;
    int size = -1;
    FOREACH (i, entry) {
      vector<Node*> path = remove(i->first, i->second);
      restore(path);
      if ((int)path.size() > size) {
        size = (int)path.size();
        best = *i;
      }
    }

    vector<Node*> path = remove(best.first, best.second);
    FOREACH (i, entry) {
      if (i->first->p[i->second]->type == 0) {
        *i = NIL;
      }
    }
    entry.erase(remove(ALL(entry), NIL), entry.end());
    ret.push_back(best);

    bool flag = greedy(entry, limit, ret);
    restore(path);
    return flag;
  }
}

static vector<Entry> temp, best;

struct FragileMirrors {
  vector<int> destory(const vector<string>& board) {
    init(board);
    greedy(entry, sz * sz, best);

    vector<int> ret;
    FOR (i, best.size()) {
      int offset = best[i].first - cell[0];
      ret.push_back(offset / MAXN - 1);
      ret.push_back(offset % MAXN - 1);
    }
    return ret;
  }
};

#ifdef __WATASHI__
int main() {
  int n;
  vector<string> board;
  vector<int> ret;

  cin >> n;
  board.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> board[i];
  }

  ret = FragileMirrors().destory(board);
  clog << "n = " << n << endl;
  clog << "r = " << ret.size() << endl;
  clog << "n/r = " << 1.0 * n / ret.size() << endl;
  clog << "time = " << 1.0 * clock() / CLOCKS_PER_SEC << endl;

  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i) {
    cout << ret[i] << endl;
  }
}
// vim: ft=cpp.doxygen
#endif
