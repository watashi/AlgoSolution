#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1000000007;

int a[MAXN], m[MAXN], g[MAXN];
vector<int> e[MAXN];

bool cmp(const pair<int, int>& lhs, const pair<int, int>& rhs) {
	return lhs.first - lhs.second < rhs.first - rhs.second;
}

pair<int, int> gao(int v, int p, bool f(const pair<int, int>&, const pair<int, int>&)) {
	vector<pair<int, int> > x;
	for (int i = 0; i < (int)e[v].size(); ++i) {
		int w = e[v][i];
		if (w != p) {
			x.push_back(gao(w, v, f));
		}
	}
	sort(x.begin(), x.end(), f);
	x.push_back(make_pair(a[v], m[v]));

	pair<int, int> ret = x[0];
	for (int i = 1; i < (int)x.size(); ++i) {
		ret.first = max(x[i].first, ret.first + x[i].second);
		ret.second += x[i].second;
	}
	return ret;
}

int main() {
	int ri = 0, n, x, y;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%d%d%d", &a[i], &m[i], &g[i]);
			m[i] += g[i];
			a[i] = max(a[i], m[i]);
			e[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d", &x, &y);
			--x;
			--y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		y = INF;
		for (int i = 0; i < n; ++i) {
			y = min(y, gao(i, -1, cmp).first);
		}
		printf("Case %d: %d\n", ++ri, y);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805857 	4788 	Castles 	Accepted 	C++ 	0.044 	2011-05-23 13:48:10
/*
id => 1174056
pid => 4788
pname => Castles
status => Accepted
lang => C++
time => 0.032
date => 2012-12-14 17:16:16
*/
