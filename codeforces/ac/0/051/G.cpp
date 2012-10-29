#include <set>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1000000000;
const int MAXN = 2048;

#define ALL(c) c.begin(), c.end()
#define FOR(i, n) for (int i = 0; i < n; ++i)
#define FOREACH(i, c) for (typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

vector<int> e[MAXN], ee[MAXN];
int depth, tag[MAXN], u[MAXN], d[MAXN];

void dfs(int v, int p) {
	tag[v] = 1;
	d[v] = depth;
	u[v] = depth;
	++depth;
	FOREACH (w, e[v]) {
		if (*w == p) {
			continue;
		}
		if (tag[*w] == 1) {
			u[v] = min(u[v], d[*w]);
		} else if (tag[*w] == -1) {
			dfs(*w, v);
			u[v] = min(u[v], u[*w]);
			if (u[*w] > d[v]) {
				ee[v].push_back(*w);
				ee[*w].push_back(v);
			}
		}
	}
	--depth;
	tag[v] = 2;
}

int build(int n) {
	fill(tag, tag + n, -1);
	depth = 0;
	FOR (i, n) {
		if (tag[i] == -1) {
			dfs(i, -1);
		}
	}

	FOR (i, n) {
		sort(ALL(e[i]));
		sort(ALL(ee[i]));
		ee[i].erase(unique(ALL(ee[i])), ee[i].end());
		e[i].erase(set_difference(ALL(e[i]), ALL(ee[i]), e[i].begin()), e[i].end());
	}

	int m = 0;

	fill(tag, tag + n, -1);
	FOR (i, n) {
		if (tag[i] == -1) {
			queue<int> q;
			tag[i] = m;
			d[m] = 1;
			q.push(i);
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				FOREACH (w, e[v]) {
					if (tag[*w] == -1) {
						tag[*w] = m;
						++d[m];
						q.push(*w);
					}
				}
			}
			++m;
		}
	}

	FOR (i, m) {
		e[i].clear();
	}
	FOR (v, n) {
		FOREACH (w, ee[v]) {
			if (tag[v] != tag[*w]) {
				e[tag[v]].push_back(tag[*w]);
			}
		}
	}

	return m;
}

int dd;

int gao(int v, int p) {
	int ret = 0, u1 = 0, u2 = 0;

	u[v] = 1;
	d[v] = 0;
	FOREACH(w, e[v]) {
		if (*w == p) {
			continue;
		}
		ret = max(ret, gao(*w, v));
		// ++u[v];	// WA40; WA41
		u[v] += d[*w];
		d[v] += d[*w];
		if (u1 < u[*w] - d[*w]) {
			u2 = u1;
			u1 = u[*w] - d[*w];
		} else if (u2 < u[*w] - d[*w]) {
			u2 = u[*w] - d[*w];
		}
	}
	if (d[v] == 0) {
		d[v] = 1;
	}
	u[v] += u1;
	ret = max(ret, u[v] + u2 + (p == -1 ? 0 : dd - d[v]));

	return ret;
}

int solve(int n) {
	int ret = 1;

	fill(tag, tag + n, -1);
	FOR (i, n) {
		if (tag[i] == -1) {
			queue<int> q;
			q.push(i);
			tag[i] = 1;
			dd = 0;
			while (!q.empty()) {
				int v = q.front();
				q.pop();
				tag[v] = 1;
				if (e[v].size() == 1) {
					++dd;
				}
				FOREACH (w, e[v]) {
					if (tag[*w] == -1) {
						tag[*w] = 1;
						q.push(*w);
					}
				}
			}
			ret += gao(i, -1) - 1;
		}
	}

	return ret;
}

int main() {
	int n, m, a, b;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	n = build(n);

	m = 0;
	for (int i = 0; i < n; ++i) {
		m += d[i] - 1;
	}
	m += n - solve(n);
	printf("%d\n", m);

	return 0;
}

// WA40
// WA41
// gao:
// 当选中某个节点时，最优的策略不是保留其所有儿子，而是保留这个子树的所有叶子！！
