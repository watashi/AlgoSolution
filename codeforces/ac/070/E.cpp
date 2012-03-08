#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 200;
const int INF = 1000000007;

int m, x[MAXN];

int d[MAXN][MAXN];
vector<int> c[MAXN], cs[MAXN];

void dfs(int v, int p) {
	c[v].erase(remove(c[v].begin(), c[v].end(), p), c[v].end());
	cs[v].push_back(v);
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		dfs(*w, v);
		cs[v].insert(cs[v].end(), cs[*w].begin(), cs[*w].end());
	}
}

typedef pair<int, int> PII;

pair<int, vector<PII> > ans[MAXN], dp[MAXN][MAXN];

int gao(int v);
int gao(int v, int p);

int gao(int v) {
	if (ans[v].first != -1) {
		return ans[v].first;
	}
	ans[v].first = INF;
	for (vector<int>::const_iterator u = cs[v].begin(); u != cs[v].end(); ++u) {
		int tmp = m + x[d[v][*u]];
		for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
			tmp += gao(*w, *u);
		}
		if (ans[v].first > tmp) {
			ans[v].first = tmp;
			ans[v].second.clear();
			ans[v].second.push_back(make_pair(v, *u));
			for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
				ans[v].second.insert(ans[v].second.end(),
					dp[*w][*u].second.begin(), dp[*w][*u].second.end());
			}
		}
	}
	return ans[v].first;
}

int gao(int v, int u) {
	if (dp[v][u].first != -1) {
		return dp[v][u].first;
	}
	gao(v);
	dp[v][u] = ans[v];
	int tmp = x[d[v][u]];
	for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
		tmp += gao(*w, u);
	}
	if (dp[v][u].first > tmp) {
		dp[v][u].first = tmp;
		dp[v][u].second.clear();
		dp[v][u].second.push_back(make_pair(v, u));
		for (vector<int>::const_iterator w = c[v].begin(); w != c[v].end(); ++w) {
			dp[v][u].second.insert(dp[v][u].second.end(),
				dp[*w][u].second.begin(), dp[*w][u].second.end());
		}
	}
	return dp[v][u].first;
}

int main() {
	int n, a, b;

	scanf("%d%d", &n, &m);
	x[0] = 0;
	for (int i = 1; i < n; ++i) {
		scanf("%d", &x[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			d[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		c[a].push_back(b);
		c[b].push_back(a);
		d[a][b] = d[b][a] = 1;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	dfs(0, -1);
	for (int i = 0; i < n; ++i) {
		ans[i].first = -1;
		for (int j = 0; j < n; ++j) {
			dp[i][j].first = -1;
		}
	}
	printf("%d\n", gao(0));
	sort(ans[0].second.begin(), ans[0].second.end());
	for (int i = 0; i < n; ++i) {
		printf("%d ", ans[0].second[i].second + 1);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443602 	May 9, 2011 3:25:53 PM 	watashi 	70E - Information Reform 	GNU C++ 	Accepted 	80 ms 	25300 KB 
