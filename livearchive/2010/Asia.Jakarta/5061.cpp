#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

template<int MAXN>
struct LG2 {
	int lg2[MAXN + 1];

	LG2() {
		lg2[0] = -1;
		for (int i = 1; i <= MAXN; i++) {
			lg2[i] = lg2[i - 1] + ((i & (i - 1)) == 0);
		}
	}

	int operator()(int x) const {
		return lg2[x];
	}
};

LG2<1 << 17> lg2;

template<int MAXL, class T = int, int MAXN = 1 << MAXL>
struct RMQ {
	int n;
	T e[MAXN];
	int rmq[MAXL][MAXN];

	static int BIN(int i) { return 1 << i; }

	int cmp(int l, int r) {
		return e[l] <= e[r] ? l : r;
	}

	void init() {
		if (n > MAXN) {
			while (true) {
			}
		}
		for (int i = 0; i < n; ++i) {
			rmq[0][i] = i;
		}
		for (int i = 0; BIN(i + 1) <= n; ++i) {
			for (int j = 0; j + BIN(i + 1) <= n; ++j) {
				rmq[i + 1][j] = cmp(rmq[i][j], rmq[i][j + BIN(i)]);
			}
		}
	}

	int index(int l, int r) {
		int b = lg2(r - l);
		return cmp(rmq[b][l], rmq[b][r - (1 << b)]);
	}

	T value(int l, int r) {
		return e[index(l, r)];
	}
};

RMQ<17> rmq;

const int MAXN = 1 << 16;

int m, i2j[MAXN], j2i[MAXN];
int u[MAXN], v[MAXN], w[MAXN];
vector<int> e[MAXN];

void dfs(int i) {
	i2j[i] = m;
	j2i[m] = i;
	++m;
	u[i] = rmq.n;
	rmq.e[rmq.n++] = i2j[i];
	for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		e[*j].erase(remove(e[*j].begin(), e[*j].end(), i), e[*j].end());
		dfs(*j);
		rmq.e[rmq.n++] = i2j[i];
	}
}

int lca(int i, int j) {
	i = u[i];
	j = u[j];
	if (i > j) {
		swap(i, j);
	}
	return j2i[rmq.value(i, j + 1)];
}

void gao(int i) {
	for (vector<int>::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		gao(*j);
		v[i] += v[*j] - 2 * w[*j];
	}
}

int main() {
	int re, n, a, b, c;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			e[i].clear();
			v[i] = w[i] = 0;
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}

		m = rmq.n = 0;
		dfs(0);
		rmq.init();

		scanf("%d", &m);
		fill(v, v + n, 0);
		fill(w, w + n, 0);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			v[a] += c;
			v[b] += c;
			w[lca(a, b)] += c;
		}

		gao(0);
		printf("Case #%d:\n", ri);
		for (int i = 0; i < n; ++i) {
			printf("%d\n", v[i] - w[i]);
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//866472 	5061 	Lightning Energy Report 	Accepted 	C++ 	0.176 	2011-08-26 05:29:26
/*
id => 1174301
pid => 5061
pname => Lightning Energy Report
status => Accepted
lang => C++
time => 0.172
date => 2012-12-14 17:51:34
*/
