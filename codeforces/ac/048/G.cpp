#include <stack>
#include <cstdio>
#include <vector>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

struct Root {
	int p, c;
	long long e, x;
	vector<int> v;
	Root(int p, long long e) : p(p), e(e) { }
};

const int MAXN = 200200;
bool oncirc[MAXN];
vector<pair<int, long long> > e[MAXN];
vector<Root> circ;
long long ans[MAXN];

bool mark[MAXN];

int dfs(int v, int p) {
	if (mark[v]) {
		return v;
	} else {
		mark[v] = true;
	}
	for (vector<pair<int, long long> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		int w = it->first;
		if (w == p) {
			continue;
		}
		int t = dfs(w, v);
		if (t != -1) {
			circ.push_back(Root(w, it->second));
			return v == t ? -1 : t;
		}
	}
	return -1;
}

int findcirc(int n) {
	int m;

	dfs(0, -1);
	m = circ.size();
	for (int i = 0; i < m; ++i) {
//printf("%d--(%lld)--", circ[i].p, circ[i].e);
		oncirc[circ[i].p] = true;
	}
//puts("");

	return m;
}

Root* root;
long long dd[MAXN], cc[MAXN], ss[MAXN], xx[MAXN];

void gao1(int v, int p) {
	root->v.push_back(v);
	cc[v] = 1;
	ss[v] = 0;
	for (vector<pair<int, long long> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		int w = it->first;
		if (w == p || oncirc[w]) {
			continue;
		}
		dd[w] = dd[v] + it->second;
		gao1(w, v);
		cc[v] += cc[w];
		ss[v] += ss[w] + cc[w] * it->second;
	}
}

void gao2(int v, int p, int n) {
	for (vector<pair<int, long long> >::const_iterator it = e[v].begin(); it != e[v].end(); ++it) {
		int w = it->first;
		if (w == p || oncirc[w]) {
			continue;
		}
		xx[w] = xx[v] + (ss[v] - (ss[w] + cc[w] * it->second)) + (n - cc[w]) * it->second;
		gao2(w, v, n);
	}
}

void calctree(Root& r) {
	root = &r;
	dd[r.p] = 0;
	gao1(r.p, -1);
	xx[r.p] = 0;
	r.c = cc[r.p];
	gao2(r.p, -1, r.c);
	for (vector<int>::const_iterator it = r.v.begin(); it != r.v.end(); ++it) {
		ans[*it] = xx[*it] + ss[*it];
	}
	r.x = ans[r.p];
}

long long ee[MAXN + MAXN];

void calccirc(int n, int m) {
	long long circlen = 0;
	long long total = 0;
	long long cursum = 0;
	int curcnt = 0;
	int q = 0;

	for (int i = 0; i < m; ++i) {
		circlen += circ[i].e;
		total += circ[i].x;
		ee[i + 1 + m] = ee[i + 1] = circ[i].e;
	}
	ee[0] = 0;
	partial_sum(ee, ee + m + m + 1, ee);

	// init
	while (2 * (ee[q] - ee[0]) <= circlen) {
		cursum += (ee[q] - ee[0]) * circ[q % m].c;
		curcnt += circ[q % m].c;
		++q;
	}
	for (int i = q; i < m; ++i) {
		cursum += (circlen - (ee[i] - ee[0])) * circ[i % m].c;
	}
//printf("total = %lld; cursum = %lld; curcnt = %d; q = %d\n", total, cursum, curcnt, q);

	for (int i = 0; i < m; ++i) {
		// adjust i
		while (2 * (ee[q] - ee[i]) <= circlen) {
			cursum -= (circlen - 2 * (ee[q] - ee[i])) * circ[q % m].c;
			curcnt += circ[q % m].c;
			++q;
		}
//printf("[%d] cursum = %lld; curcnt = %d; curc.x = %lld, q = %d\n", circ[i].p, cursum, curcnt, circ[i].x, q);
		// update
		for (vector<int>::const_iterator it = circ[i].v.begin(); it != circ[i].v.end(); ++it) {
//printf("{%d} ans = %lld; dd = %lld; del = %lld; n - c = %d - %d\n", *it, ans[*it],  dd[*it], cursum + total - circ[i].x, n, circ[i].c);
			ans[*it] += cursum + total - circ[i].x + dd[*it] * (n - circ[i].c);
		}
		// shift i->i+1
		curcnt -= circ[i].c;
		cursum += (n - curcnt) * circ[i].e;
		cursum -= curcnt * circ[i].e;
	}
}

int main() {
	int n, m, a, b, c;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}

	m = findcirc(n);
	for (int i = 0; i < m; ++i) {
		calctree(circ[i]);
	}
	calccirc(n, m);

	for (int i = 0; i < n; ++i) {
		printf("%I64d%c", ans[i], i == n - 1 ? '\n' : ' ');
//		printf("%lld%c", ans[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218368 	Dec 12, 2010 3:37:55 PM 	watashi 	G - Galaxy Union 	GNU C++ 	Accepted 	690 ms 	45712 KB 
