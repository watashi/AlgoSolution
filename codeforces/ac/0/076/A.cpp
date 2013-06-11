#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 218;
const int MAXM = 65536;
const long long INF = 2LL * 1000000007LL * 1000000007LL;

struct Edge {
	int x, y, g, s;
	bool operator<(const Edge& o) const { return g < o.g; }
	int to(int from) const { return from == x ? y : x; }
} edge[MAXM];

vector<int> e[MAXN];

int dfs(int s, int t, int p) {
	for (vector<int>::const_iterator i = e[s].begin(); i != e[s].end(); ++i) {
		int j = edge[*i].to(s);
		if (j == t) {
			return *i;
		} else if (j != p) {
			int k = dfs(j, t, s);
			if (k != -1) {
				return edge[k].s > edge[*i].s ? k : *i;
			}
		}
	}
	return -1;
}

int main() {
	int n, m, g, s;
	long long ans;
	multiset<int> ms;

	scanf("%d%d%d%d", &n, &m, &g, &s);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d%d", &edge[i].x, &edge[i].y, &edge[i].g, &edge[i].s);
	}
	sort(edge, edge + m);

	ans = INF;
	for (int i = 0; i < m; ++i) {
		if (edge[i].x == edge[i].y) {
			continue;
		}
		int j = dfs(edge[i].x, edge[i].y, -1);
		if (j == -1) {
			--n;
			e[edge[i].x].push_back(i);
			e[edge[i].y].push_back(i);
			ms.insert(edge[i].s);
		} else if (edge[i].s < edge[j].s) {
			e[edge[j].x].erase(find(e[edge[j].x].begin(), e[edge[j].x].end(), j));
			e[edge[j].y].erase(find(e[edge[j].y].begin(), e[edge[j].y].end(), j));
			ms.erase(ms.find(edge[j].s));
			e[edge[i].x].push_back(i);
			e[edge[i].y].push_back(i);
			ms.insert(edge[i].s);
		}
		if (n == 1) {
			ans = min(ans, 1LL * g * edge[i].g + 1LL * s * *ms.rbegin());
		}
	}
	
//	printf("%lld\n", ans == INF ? -1 : ans);
	printf("%I64d\n", ans == INF ? -1 : ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443996 	May 9, 2011 10:49:42 PM 	watashi 	76A - Gift 	GNU C++ 	Accepted 	220 ms 	2400 KB 
