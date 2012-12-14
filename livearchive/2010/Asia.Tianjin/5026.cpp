#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 3000;
const int INF = 1000000007;

struct Edge {
	int a, b, c;
} edge[MAXN];

int mindis, maxlen;
int d[MAXN], t[MAXN], w[MAXN], u[MAXN];
vector<pair<int, int> > e[MAXN];

void dfs(int i, int p) {
	d[i] = t[i] = 0;
	w[i] = -1;
	for (vector<pair<int, int> >::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		if (j->first == p) {
			continue;
		}
		dfs(j->first, i);
		if (d[i] < d[j->first] + j->second) {
			t[i] = d[i];
			d[i] = d[j->first] + j->second;
			w[i] = j->first;
		} else if (t[i] < d[j->first] + j->second) {
			t[i] = d[j->first] + j->second;
		}
	}
	maxlen = max(maxlen, d[i] + t[i]);
}

void gao(int i, int p) {
	for (vector<pair<int, int> >::const_iterator j = e[i].begin(); j != e[i].end(); ++j) {
		if (j->first == p) {
			continue;
		}
		u[j->first] = max(u[i], j->first != w[i] ? d[i] : t[i]) + j->second;
		gao(j->first, i);
	}
//	printf("@%d: %d %d %d %d\n", i, d[i], t[i], w[i], u[i]);
	mindis = min(mindis, max(u[i], d[i]));
}

int main() {
	int re, n, ans, sum;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			e[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			scanf("%d%d%d", &edge[i].a, &edge[i].b, &edge[i].c);
			e[edge[i].a].push_back(make_pair(edge[i].b, edge[i].c));
			e[edge[i].b].push_back(make_pair(edge[i].a, edge[i].c));
		}

		ans = INF;
		for (int i = 1; i < n; ++i) {
			maxlen = 0;
			sum = edge[i].c;
	//		printf("[%d]", i);

			mindis = INF;
			dfs(edge[i].a, edge[i].b);
			u[edge[i].a] = 0;
			gao(edge[i].a, edge[i].b);
			sum += mindis;
	//		printf(" %d", mindis);
		
			mindis = INF;
			dfs(edge[i].b, edge[i].a);
			u[edge[i].b] = 0;
			gao(edge[i].b, edge[i].a);
			sum += mindis;
	//		printf(" %d s=%d m=%d\n", mindis, sum, maxlen);
		
			ans = min(ans, max(sum, maxlen));
		}
		printf("Case %d: %d\n", ri, ans);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798500 	5026 	Building Roads 	Accepted 	C++ 	0.884 	2011-05-13 09:44:30
/*
id => 1174260
pid => 5026
pname => Building Roads
status => Accepted
lang => C++
time => 0.773
date => 2012-12-14 17:46:13
*/
