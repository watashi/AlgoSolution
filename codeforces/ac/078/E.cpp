#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 300;
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

const int MAX = 12;
const int INF = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int n;
char sci[MAX][MAX], rec[MAX][MAX];
int d[MAX][MAX], t[MAX][MAX];

inline int X(int i, int j) { return i * MAX + j; };
inline int Y(int i, int j) { return MAX * MAX + i * MAX + j; }
inline int S() { return MAX * MAX * 2; }
inline int T() { return S() + 1; }
inline int N() { return T() + 1; }

void bfs(int n) {
	queue<pair<int, int> > q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = INF;
			if (sci[i][j] == 'Z') {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (0 <= xx && xx < n && 0 <= yy && yy < n
					&& isdigit(sci[xx][yy]) && d[xx][yy] == INF) {
				d[xx][yy] = d[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

void gao(int n, int m, int sx, int sy) {
	queue<pair<int, int> > q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			t[i][j] = INF;
		}
	}
	q.push(make_pair(sx, sy));
	t[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (t[x][y] > m) {
			break;
		}
		if (t[x][y] <= d[x][y] && isdigit(rec[x][y]) && rec[x][y] != '0') {
	//		printf("%d %d\n", x, y);
			fn.addEdge(X(sx, sy), Y(x, y), 11);
		}
		if (t[x][y] >= d[x][y]) {
			continue;
		}
		for (int k = 0; k < 4; ++k) {
			int xx = x + dx[k];
			int yy = y + dy[k];
			if (0 <= xx && xx < n && 0 <= yy && yy < n
					&& isdigit(sci[xx][yy]) && t[xx][yy] == INF) {
				t[xx][yy] = t[x][y] + 1;
				q.push(make_pair(xx, yy));
			}
		}
	}
}

int main() {
	int n, m;

	scanf("%d%d", &n, &m);
	fn.init(N(), S(), T());
	for (int i = 0; i < n; ++i) {
		scanf("%s", sci[i]);
		for (int j = 0; j < n; ++j) {
			if (isdigit(sci[i][j]) && sci[i][j] != '0') {
				fn.addEdge(S(), X(i, j), sci[i][j] - '0');
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s", rec[i]);
		for (int j = 0; j < n; ++j) {
			if (isdigit(rec[i][j]) && rec[i][j] != '0') {
				fn.addEdge(Y(i, j), T(), rec[i][j] - '0');
			}
		}
	}

	bfs(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (isdigit(sci[i][j]) && sci[i][j] != '0') {
	//			printf("gao(%d, %d)\n", i, j);
				gao(n, m, i, j);
			}
		}
	}
	printf("%d\n", fn.sap());

	return 0;
}

