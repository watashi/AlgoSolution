#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

const int MAXB = 17;
const int MAXN = 100100;
const long long INF = 1LL << 40;

typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, PII> PLPII;

struct DisjointSet {
	int p[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int root(int i) {
		return p[i] = p[i] == i ? i : root(p[i]);
	}

	bool setp(int i, int j) {
		i = root(i);
		j = root(j);
		if (i != j) {
			p[i] = j;
			return true;
		} else {
			return false;
		}
	}
} ds;

vector<PIL> e[MAXN];
vector<PLPII> ex;
int d[MAXN];
PIL p[MAXN][MAXB];

void dfs(int u, int v) {
	for (int i = 1; i < MAXB; ++i) {
		const PIL& q = p[p[u][i - 1].fst][i - 1];
		p[u][i].fst = q.fst;
		p[u][i].snd = max(p[u][i - 1].snd, q.snd);
	}
	for (vector<PIL>::const_iterator it = e[u].begin(); it != e[u].end(); ++it) {
		int w = it->fst;
		if (w == v) {
			continue;
		}
		d[w] = d[u] + 1;
		p[w][0].fst = u;
		p[w][0].snd = it->snd;
		dfs(w, u);
	}
}

PIL up(int u, int n) {
	long long snd = 0;

	for (int i = 0; n > 0; ++i) {
		if (n % 2 != 0) {
			snd = max(snd, p[u][i].snd);
			u = p[u][i].fst;
		}
		n >>= 1;
	}

	return make_pair(u, snd);
}

long long gao(int u, int v) {
	int l = 0, r = min(d[u], d[v]) + 1, m;

	while (l < r) {	// TODO: faster LCA
		m = (l + r) / 2;
		if (up(u, d[u] - m).fst == up(v, d[v] - m).fst) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	m = l - 1;

	return max(up(u, d[u] - m).snd, up(v, d[v] - m).snd);
}

int main() {
	int n, m, a, b, c;
	long long sum, ans;

	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i) {
		ex.push_back(make_pair(INF, make_pair(i - 1, i)));
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		ex.push_back(make_pair(c, make_pair(a - 1, b - 1)));
	}
	sort(ex.begin(), ex.end());
	ds.init(n);
	sum = 0;
	for (vector<PLPII>::const_iterator it = ex.begin(); it != ex.end(); ++it) {
		if (ds.setp(it->snd.fst, it->snd.snd)) {
			sum += it->fst;
			e[it->snd.fst].push_back(make_pair(it->snd.snd, it->fst));
			e[it->snd.snd].push_back(make_pair(it->snd.fst, it->fst));
		}
	}

	d[0] = 0;
	p[0][0] = make_pair(0, 0);
	dfs(0, -1);
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		ans = sum - gao(a - 1, b - 1);
	//	printf("%lld\n", ans < INF ? ans : -1LL);
		printf("%I64d\n", ans < INF ? ans : -1LL);
	}

	return 0;
}

// <orz myself>
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//213473 	Dec 11, 2010 10:09:15 PM 	watashi 	E - Baldman and the military 	GNU C++ 	Accepted 	1670 ms 	50032 KB 

