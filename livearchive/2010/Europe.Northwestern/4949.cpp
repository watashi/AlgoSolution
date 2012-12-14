#include <queue>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int MAXM = MAXN * MAXN;
const int INF = 1000000007;
inline int RE(int i) { return i ^ 1; }

struct Edge {
	int v;
	int c;
};

struct NoSuchFlowException {
};

struct ExtFlowNetwork {
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

inline int IN(int i) {
	return i << 1;
}

inline int OUT(int i) {
	return IN(i) ^ 1;
}

int main() {
	int re, n, l, r, s, m, a[MAXN];
	bool b[MAXN];
	char e[MAXN][MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		fill(b, b + n, false);
		for (int i = 0; i < n; ++i) {
			scanf("%s", e[i]);
			for (int j = 0; j < n; ++j) {
				if (e[i][j] == 'Y' && a[j] == 0) {
					b[i] = true;
				}
			}
		}

		l = 0;
		r = accumulate(a, a + n, 1);
		while (l < r) {
			s = 0;
			m = (l + r) / 2;
			fn.init(2 * (n + 1), IN(n), OUT(n));
			for (int i = 0; i < n; ++i) {
				if (a[i] > 0) {
					fn.addEdge(IN(n), IN(i), a[i]);
					fn.addEdge(IN(i), OUT(i), a[i]);
					fn.addEdge(IN(i), OUT(n), b[i] ? m : 1);
					s += b[i] ? m : 1;
				}
				for (int j = 0; j < n; ++j) {
					if (e[i][j] == 'Y') {
						fn.addEdge(OUT(i), IN(j), INF);
					}
				}
			}
			if (fn.sap() == s) {
				l = m + 1;
			} else {
				r = m;
			}
		}
		printf("%d\n", r - 1);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881084 	4949 	Risk 	Accepted 	C++ 	0.028 	2011-09-13 09:36:33
/*
id => 1174275
pid => 4949
pname => Risk
status => Accepted
lang => C++
time => 0.026
date => 2012-12-14 17:47:32
*/
