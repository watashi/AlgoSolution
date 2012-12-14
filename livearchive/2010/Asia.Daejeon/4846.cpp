#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
int x[MAXN], y[MAXN], z[MAXN];
vector<int> e[MAXN];
int dfn[MAXN], low[MAXN], id[MAXN], num, st[MAXN], top, in[MAXN], tot;
bool mark[MAXN];

void tarjan(int now) {
	in[st[top++] = now] = true;
	dfn[now] = low[now] = ++tot;
	int i;
	for (int ii = e[now].size() - 1; ii >= 0; --ii) {
		i = e[now][ii];
		if (!dfn[i]) {
			tarjan(i);
			low[now] = min(low[now], low[i]);
		} else if (in[i]) {
			low[now] = min(low[now], dfn[i]);
		}
	}
	if (dfn[now] == low[now]) {
		do {
			i = st[--top];
			in[i] = false;
			id[i] = num;
		} while (i != now);
		++num;
	}
}

void components(int n) {
	fill(dfn, dfn + n, 0);
	fill(low, low + n, 0);
	fill(in, in + n, 0);
	fill(id, id + n, -1);
	for (int i = top = num = tot = 0; i < n; ++i) {
		if (!dfn[i]) {
			tarjan(i);
		}
	}
}

int main() {
	int re, n, m;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			x[i] *= 2;
			y[i] *= 2;
			e[i].clear();
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				if (abs(x[i] - x[j]) <= z[i] && abs(y[i] - y[j]) <= z[i]) {
					e[i].push_back(j);
				}
			}
		}
		components(n);
		m = num;
		fill(mark, mark + m, false);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)e[i].size(); ++j) {
				if (id[i] != id[e[i][j]]) {
					mark[id[e[i][j]]] = true;
				}
			}
		}
		printf("%d\n", count(mark, mark + m, false));
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714856  	2011-01-03 16:37:21 	Accepted	1.316	884	26909	C++	4846 - Mines
/*
id => 1174203
pid => 4846
pname => Mines
status => Accepted
lang => C++
time => 0.385
date => 2012-12-14 17:37:49
*/
