#include <map>
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

inline void startTimer() {
  gettimeofday(&tv, NULL);
  startll = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec + TIME_LIMIT;
}

inline bool timeout() {
  gettimeofday(&tv, NULL);
  endll = tv.tv_sec * MSEC_PER_SEC + tv.tv_usec;
  return endll > startll;
}

const int MAXN = 105;
const int R = 0, D = 1, U = 2, L = 3;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

struct Node {
  Node *p[4];
  int type, hash;
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
      cell[i][j].hash = rand();
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

inline int remove(Node* cur, int dir, vector<Node*>& ret) {
  int hash = 0;
  while (true) {
    cur = cur->p[dir];
    if (cur->type == 0) {
      break;
    } else {
      hash ^= cur->hash;
      detach(cur);
      ret.push_back(cur);
      dir ^= cur->type;
    }
  }
  return hash;
}

inline int restore(const vector<Node*>& v) {
  int hash = 0;
  for (vector<Node*>::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it) {
    hash ^= (*it)->hash;
    atach(*it);
  }
  return hash;
}

inline void compact(vector<Entry>& entry) {
  FOREACH (i, entry) {
    if (i->first->p[i->second]->type == 0) {
      *i = NIL;
    }
  }
  entry.erase(remove(ALL(entry), NIL), entry.end());
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
      vector<Node*> path;
      remove(i->first, i->second, path);
      restore(path);
      if ((int)path.size() > size) {
        size = (int)path.size();
        best = *i;
      }
    }

    vector<Node*> path;
    bool flag;

    remove(best.first, best.second, path);
    ret.push_back(best);
    compact(entry);
    flag = greedy(entry, limit, ret);
    restore(path);
    return flag;
  }
}

static vector<Entry> best;

inline void search(int limit) {
  vector<vector<Entry> > todo;
  todo.push_back(vector<Entry>());
  for (int step = 1; !timeout() && step < (int)best.size(); ++step) {
    map<pair<int, int>, vector<Entry> > top;
    FOREACH (i, todo) {
      vector<Node*> done;
      vector<Entry> temp = *i, entry = ::entry;
      int hash = 0;
      FOREACH (j, temp) {
        hash ^= remove(j->first, j->second, done);
      }
      int size = (int)done.size();
      compact(entry);

      FOREACH (j, entry) {
        vector<Node*> path;
        hash ^= remove(j->first, j->second, path);
        size += (int)path.size();
        temp.push_back(*j);
        if (size == sz * sz) {
#ifdef __WATASHI__
          clog << "r" << limit << " = " << step << endl;
#endif
          best = temp;
          restore(path);
          restore(done);
          return;
        } else if ((int)top.size() < limit) {
          top[make_pair(size, hash)] = temp;
        } else if (make_pair(size, hash) > top.begin()->first) {
          top.erase(top.begin());
          top[make_pair(size, hash)] = temp;
        }
        temp.pop_back();
        size -= (int)path.size();
        hash ^= restore(path);
      }

      restore(done);
      if (timeout()) {
        return;
      }
    }
    todo.clear();
    FOREACH (j, top) {
      todo.push_back(j->second);
    }
  }
}

struct FragileMirrors {
  vector<int> destroy(const vector<string>& board) {
    startTimer();
    init(board);
    greedy(entry, sz * sz, best);
#ifdef __WATASHI__
    clog << "n = " << board.size() << endl;
    clog << "r1 = " << best.size() << endl;
#endif
    int limit = 32;
    while (true) {
      search(limit);
      if (timeout()) {
        break;
      } else {
        limit *= 2;
      }
    }
#ifdef __WATASHI__
    clog << "limit = " << limit << endl;
    clog << "time = " << (double)clock() / CLOCKS_PER_SEC << endl;
    clog << "score = " << (double)board.size() / best.size() << endl;
#endif

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

  ret = FragileMirrors().destroy(board);
  cout << ret.size() << endl;
  for (int i = 0; i < (int)ret.size(); ++i) {
    cout << ret[i] << endl;
  }
}
// vim: ft=cpp.doxygen
#endif
