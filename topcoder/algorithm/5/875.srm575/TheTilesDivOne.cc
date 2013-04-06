#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <utility>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define ALL(c) (c).begin(), (c).end()
#define FOR(i, n) for (int i = 0; i < (int)(n); ++i)
#define FOREACH(i, n) for (__typeof(n.begin()) i = n.begin(); i != n.end(); ++i)
#define MEMSET(p, c) memset(p, c, sizeof(p))
typedef long long llint;
typedef pair<int, int> PII;
/// BEGIN CUT HERE
inline void errf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  vfprintf(stderr, fmt, args);
  va_end(args);
}

template<typename T>
inline void errf(const char *fmt, const vector<T>& v) {
  errf("{");
  FOR(i, v.size()) {
    errf(fmt, v[i]);
  }
  errf("}\n");
}
// TODO
/// END CUT HERE
#ifndef __WATASHI__
#define errf(fmt, ...) do { } while (false)
#endif

struct TheTilesDivOne {
  int find(vector <string> board);
};

const int MAXN = 10086;
const int MAXM = 65536;
inline int RE(int i) { return i ^ 1; }

struct Edge {
	int v;
	int c;
};

struct FlowNetwork {
	int n, m, source, sink;
	vector<int> e[MAXN];
	Edge edge[MAXM * 2];

	void init(int n, int source, int sink) {	// if no source & sink, then source = sink = -1
		this->n = n;
		this->m = 0;
		this->source = source;
		this->sink = sink;
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
	}

	void addEdge(int a, int b, int c) {
		edge[m].v = b;
		edge[m].c = c;
		e[a].push_back(m);
		edge[m + 1].v = a;
		edge[m + 1].c = 0;
		e[b].push_back(m + 1);
		m += 2;
	}

	// shortest augmenting path
	int c[MAXN];		//*
	int d[MAXN];		//*
	int done[MAXN];		//*
	int path[MAXN];		//*
	int len;			//*

	void _bfs() {
		queue<int> q;
		fill(c, c + n, 0);
		fill(d, d + n, n);	// n->inf
		d[sink] = 0;
		q.push(sink);
		while (!q.empty()) {
			int cur = q.front();
			++c[d[cur]];
			for (size_t i = 0; i < e[cur].size(); ++i) {
				int id = e[cur][i];
				if (d[edge[id].v] == n && edge[RE(id)].c > 0) {
					d[edge[id].v] = d[cur] + 1;
					q.push(edge[id].v);
				}
			}
			q.pop();
		}
	}

	void _retreat(int v) {
		--c[d[v]];
		d[v] = n;	// n->inf
		for (size_t i = 0; i < e[v].size(); ++i) {
			Edge &arc = edge[e[v][i]];
			if (d[v] > d[arc.v] + 1 && arc.c > 0) {
				d[v] = d[arc.v] + 1;
				done[v] = i;	// ~
			}
		}
		++c[d[v]];
	}

	int _augment() {
		int todo = -1;
		int flow = 0x7fffff;
		for (int i = 0; i < len; ++i) {
			Edge &arc = edge[e[path[i]][done[path[i]]]];
			if (arc.c < flow) {
				flow = arc.c;
				todo = i;
			}
		}
		for (int i = 0; i < len; ++i) {
			int id = e[path[i]][done[path[i]]];
			edge[id].c -= flow;
			edge[RE(id)].c += flow;
		}
		len = todo;
		return flow;
	}

	int sap() {
		int flow = 0;
		_bfs();
		fill(done, done + n, 0);
		len = 0;
		path[0] = source;
		while (d[source] != n/* && len >= 0*/) {	// n->inf
			int back = path[len];
			if (back == sink) {
				flow += _augment();
			} else {
				while (done[back] < (int)e[back].size()) {
					Edge &arc = edge[e[back][done[back]]];
					if (d[arc.v] == d[back] - 1 && arc.c > 0) {
						break;
					} else {
						++done[back];
					}
				}
				if (done[back] == (int)e[back].size()) {
					if (c[d[back]] == 1) {
						break;	// return;
					} else {
						_retreat(back);
						if (back != source) {	// !!
							--len;	// pop
						}
					}
				} else {
					path[++len] = edge[e[back][done[back]]].v;	// push
				}
			}
		}
		return flow;
	}
	// end of sap
} fn;

inline int IN(int i) { return i << 1; }
inline int OUT(int i) { return IN(i) ^ 1; }

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int TheTilesDivOne::find(vector <string> s) {
  int r = s.size();
  int c = s[0].size();
  int n = r * c;
  fn.init(n * 2 + 2, IN(n), OUT(n));
  FOR (i, n) {
    fn.addEdge(IN(i), OUT(i), 1);
  }
  FOR (i, r) {
    FOR (j, c) {
      if ((i + j) % 2 != 0 && s[i][j] != 'X') {
        if (i % 2 != 0) {
          fn.addEdge(IN(n), IN(i * c + j), 1);
        } else {
          fn.addEdge(OUT(i * c + j), OUT(n), 1);
        }
        FOR (k, 4) {
          int ii = i + dx[k];
          int jj = j + dy[k];
          if (0 <= ii && ii < r && 0 <= jj && jj < c && s[ii][jj] != 'X') {
            if (i % 2 != 0) {
              fn.addEdge(OUT(i * c + j), IN(ii * c + jj), 1);
            } else {
              fn.addEdge(OUT(ii * c + jj), IN(i * c + j), 1);
            }
          }
        }
      }
    }
  }
  return fn.sap();
}

/// BEGIN CUT HERE
// TODO
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  os << "{";
  FOR(i, v.size()) {
    os << "\"" << v[i] << "\",";
  }
  os << "}";

  return os;
}

vector<bool> __eq__;

template<typename S, typename T>
void eq(int id, S v1, T v2) {
  ostringstream s1, s2;

  s1 << v1;
  s2 << v2;

  errf("Case #%d: ", id);
  if (s1.str() == s2.str()) {
    __eq__.push_back(true);
    errf("\033[1;32mPassed\033[0m\n");
  } else {
    __eq__.push_back(false);
    errf("\033[1;31mFailed\033[0m\n");
    errf("\tReceived \"%s\"\n", s1.str().c_str());
    errf("\tExpected \"%s\"\n", s2.str().c_str());
  }
}

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

      {
        string boardARRAY[] = {"X.X",
            "...",
            "X.X"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheTilesDivOne theObject;
        eq(0, theObject.find(board),1);
    }
    {
        string boardARRAY[] = {"...",
            "...",
            "..."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheTilesDivOne theObject;
        eq(1, theObject.find(board),2);
    }
    {
        string boardARRAY[] = {"......X.X.XXX.X.XX."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheTilesDivOne theObject;
        eq(2, theObject.find(board),0);
    }
    {
        string boardARRAY[] = {"X.....XXX.XX..XXXXXXXXX...X.XX.XX....X",
            ".XXXX..X..XXXXXXXX....XX.X.X.X.....XXX",
            "....XX....X.XX..X.X...XX.X..XXXXXXX..X",
            "XX.XXXXX.X.X..X..XX.XXX..XX...XXX.X..."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        TheTilesDivOne theObject;
        eq(3, theObject.find(board),13);
    }

  int __pass__ = count(ALL(__eq__), true);
  int __fail__ = count(ALL(__eq__), false);
  if (__fail__ == 0) {
    errf("\033[1;32mAll %d Passed\033[0m\n", __pass__);
  } else if (__pass__ == 0) {
    errf("\033[1;31mAll %d Failed\033[0m\n", __fail__);
  } else {
    errf("\033[1;31m%d Passed; %d Failed\033[0m\n", __pass__, __fail__);
    if (__eq__[0]) {
      errf("\033[1;31mDid you reset global variables?\033[0m\n");
    }
  }
  errf("\033[1;33mPress any key to continue...\033[0m\n");
  getchar();

  return 0;
}

/*
 * __builtin_popcount __builtin_ctz make_pair
 * priority_queue
 * push_back
 * first second iterator const_iterator
 */
/*
 * vim: ft=cpp.doxygen
 */
/// END CUT HERE
