// 最小度限制生成树
// Degree-constrained minimum spanning tree (DCMST)

#include <map>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 5050;
const int INF = 1000000007;

struct DisjointSet {
	int p[MAXN];

	void init(int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int getp(int i) {
		return p[i] == i ? i : (p[i] = getp(p[i]));
	}

	bool setp(int i, int j) {
		i = getp(i);
		j = getp(j);
		if (i != j) {
			p[i] = j;
			return true;
		} else {
			return false;
		}
	}
} ds;

map<pair<int, int>, int> id;
int a, b, c, d, g, v[MAXN];
vector<pair<int, int> > e[MAXN];
vector<pair<int, pair<int, int> > > ee;

void dump(int t, int f) {
	for (const auto& p: e[t]) {
		if (p.first != f) {
			printf("%d ", id[make_pair(min(t, p.first), max(t, p.first))] + 1);
			dump(p.first, t);
		}
	}
}

void dfs(int t, int f, int x, int y, int z) {
	if (v[t] != -1) {
		if (d > v[t] - z) {
			d = v[t] - z;
			g = t;
			a = x;
			b = y;
			c = z;
		}
	}
	for (const auto& p: e[t]) {
		if (p.first != f) {
			if (p.second > z) {
				dfs(p.first, t, p.first, t, p.second);
			} else {
				dfs(p.first, t, x, y, z);
			}
		}
	}
}

int main() {
	int n, m, k, ans;

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		--a;
		--b;
		if (a > b) {
			swap(a, b);
		}
		id[make_pair(a, b)] = i;
		ee.push_back({c, {a, b}});
	}
	sort(ee.begin(), ee.end());

	ds.init(n);
	ans = 0;
	for (int i = 0; i < m; ++i) {
		a = ee[i].second.first;
		b = ee[i].second.second;
		c = ee[i].first;
		if (a != 0 && ds.setp(a, b)) {
			ans += c;
			e[a].push_back({b, c});
			e[b].push_back({a, c});
		}
	}
	fill(v, v + n, -1);
	for (int i = 0; i < m; ++i) {
		a = ee[i].second.first;
		b = ee[i].second.second;
		c = ee[i].first;
		if (a == 0) {
			if (ds.setp(a, b)) {
				--k;
				ans += c;
				e[a].push_back({b, c});
				e[b].push_back({a, c});
			} else {
				v[b] = c;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (ds.getp(i) != ds.getp(0)) {
			k = -1;
		}
	}

	if (k < 0 || k > n - (int)count(v, v + n, -1)) {
		puts("-1");
		return 0;
	}

	while (k-- > 0) {
		d = INF;
		for (const auto& p: e[0]) {
			dfs(p.first, 0, -1, -1, -1);
		}
		ans += d;
		e[a].erase(find(e[a].begin(), e[a].end(), make_pair(b, c)));
		e[b].erase(find(e[b].begin(), e[b].end(), make_pair(a, c)));
		e[0].push_back({g, v[g]});
		e[g].push_back({0, v[g]});
		v[g] = -1;
	}
	printf("%d\n", n - 1);
	dump(0, -1);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863451 	Nov 14, 2011 6:30:09 PM 	watashi 	125E - MST Company 	GNU C++0x 	Accepted 	220 ms 	7100 KB 
