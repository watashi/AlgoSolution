#include <queue>
#include <cstdio>
#include <vector>
#include <cassert>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int MAXM = 10086;
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

int eid[MAXN][MAXN];

void dec(int k) {
	++fn.edge[k].c;
	--fn.edge[RE(k)].c;
}

int main() {
	bool blank = false;
	int n, m, x[MAXN], y[MAXN], z;
	char ans[MAXN][MAXN];

	while (scanf("%d%d", &n, &m) != EOF && n > 0 && m > 0) {
		if (blank) {
			puts("");
		} else {
			blank = true;
		}

		fn.init(n + m + 2, n + m, n + m + 1);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x[i]);
			eid[n + m][i] = fn.m;
			fn.addEdge(n + m, i, x[i]);
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", &y[i]);
			eid[n + i][n + m + 1] = fn.m;
			fn.addEdge(n + i, n + m + 1, y[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				eid[i][n + j] = fn.m;
				fn.addEdge(i, n + j, 1);
			}
		}
		z = fn.sap();
		if (z != accumulate(x, x + n, 0) || z != accumulate(y, y + m, 0)) {
			puts("Impossible");
			continue;
		}

		for (int i = 0; i < n; ++i) {
			fill(ans[i], ans[i] + m, 'N');
			ans[i][m] = '\0';
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int k = eid[i][n + j];
				if (fn.edge[k].c == 1) {
					fn.edge[k].c = 0;
				} else {
					int s = eid[n + m][i], t = eid[n + j][n + m + 1];
					dec(s);
					dec(k);
					dec(t);
					fn.edge[k].c = 0;
					if (fn.sap() == 0) {
						assert(fn.edge[s].c == 1);
						--fn.edge[s].c;
						assert(fn.edge[t].c == 1);
						--fn.edge[t].c;
						ans[i][j] = 'Y';
					}
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			puts(ans[i]);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//904147 	4957 	Fake scoreboard 	Accepted 	C++ 	0.732 	2011-10-11 13:42:12
/*
id => 1174214
pid => 4957
pname => Fake scoreboard
status => Accepted
lang => C++
time => 0.488
date => 2012-12-14 17:39:46
*/
