#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2525;

// [MODULE: StrongComponents Tarjan]
struct Graph {
	int n, m;
	vector<int> e[MAXN], s;
	int timestamp, ts[MAXN], low[MAXN], id[MAXN], color[MAXN];

	void gao(int v) {
		s.push_back(v);
		color[v] = 1;
		ts[v] = low[v] = timestamp++;
		for (vector<int>::const_iterator w = e[v].begin(); w != e[v].end(); ++w) {
			if (color[*w] == 0) {
				gao(*w);
				low[v] = min(low[v], low[*w]);
			} else if (color[*w] == 1) {
				low[v] = min(low[v], ts[*w]);
			}
		}
		if (ts[v] == low[v]) {
			while (true) {
				color[s.back()] = 2;
				id[s.back()] = m;
				if (s.back() == v) {
					s.pop_back();
					break;
				} else {
					s.pop_back();
				}
			}
			++m;
		}
	}

	void tarjan() {
		m = 0;
		s.clear();
		timestamp = 0;
		fill(color, color + n, 0);
		for (int i = 0; i < n; ++i) {
			if (color[i] == 0) {
				gao(i);
			}
		}
	}
} g, gg;

int s[MAXN], c[MAXN];
vector<int> e[MAXN];
bitset<MAXN> bs[MAXN];

int main() {
	int re, m, a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &g.n, &m);
		for (int i = 0; i < g.n; ++i) {
			g.e[i].clear();
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			--a;
			--b;
			g.e[a].push_back(b);
		}
		g.tarjan();

		for (int i = 0; i < g.m; ++i) {
			s[i] = c[i] = 0;
			e[i].clear();
			bs[i].reset();
			bs[i].set(i);
		}
		for (int i = 0; i < g.n; ++i) {
			++s[g.id[i]];
			for (vector<int>::const_iterator j = g.e[i].begin(); j != g.e[i].end(); ++j) {
				if (g.id[i] != g.id[*j]) {
					e[g.id[i]].push_back(g.id[*j]);
				}
			}
		}
		for (int i = 0; i < g.m; ++i) {
			sort(e[i].begin(), e[i].end());
			e[i].erase(unique(e[i].begin(), e[i].end()), e[i].end());
			for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
				++c[*j];
			}
		}

		queue<int> q;
		for (int i = 0; i < g.m; ++i) {
			if (c[i] == 0) {
				q.push(i);
			}
		}
		b = -g.n;
		while (!q.empty()) {
			a = q.front();
			for (int j = 0; j < g.m; ++j) {
				if (bs[a].test(j)) {
					b += s[a] * s[j];
				}
			}
			for (vector<int>::const_iterator j = e[a].begin(); j != e[a].end(); ++j) {
				bs[*j] |= bs[a];
				if (--c[*j] == 0) {
					q.push(*j);
				}
			}
			q.pop();
		}
		printf("%d\n", b);
	}

	return 0;
}

// even O(VE) is fast enough for this prob!

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//864742 	5062 	Transitive Closure 	Accepted 	C++ 	0.060 	2011-08-24 06:01:38
/*
id => 1174304
pid => 5062
pname => Transitive Closure
status => Accepted
lang => C++
time => 0.049
date => 2012-12-14 17:51:52
*/
