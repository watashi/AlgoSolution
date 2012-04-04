#include <set>
#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const int INF = 1000000007;

int d[MAXN];
int dp[1 << 20];

int main() {
	int l, m, n;
	set<int> s;
	int x[128], a[128], b[20][20];

	scanf("%d%d%d", &l, &m, &n);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &x[i]);
	}
	sort(x, x + m);
	m = unique(x, x + m) - x;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	n = unique(a, a + n) - a;

	for (int i = 0; i < m; ++i) {
		pair<set<int>::iterator, bool> p;
		p = s.insert(x[i] - 1);
		if (!p.second) {
			s.erase(p.first);
		}
		p = s.insert(x[i]);
		if (!p.second) {
			s.erase(p.first);
		}
	}
	m = copy(s.begin(), s.end(), x) - x;

	for (int i = 0; i < m; ++i) {
		priority_queue<pair<int, int> > pq;
		fill(d, d + l + 1, INF);
		d[x[i]] = 0;
		pq.push(make_pair(-d[x[i]], x[i]));
		while (!pq.empty()) {
			int s = pq.top().second;
			int t = -pq.top().first;
			pq.pop();
			if (d[s] != t) {
				continue;
			}
			for (int i = 0; i < n && a[i] <= s; ++i) {
				if (d[s - a[i]] > t + 1) {
					d[s - a[i]] = t + 1;
					pq.push(make_pair(-d[s - a[i]], s - a[i]));
				}
			}
			for (int i = 0; i < n && a[i] + s <= l; ++i) {
				if (d[s + a[i]] > t + 1) {
					d[s + a[i]] = t + 1;
					pq.push(make_pair(-d[s + a[i]], s + a[i]));
				}
			}
		}
		for (int j = 0; j < m; ++j) {
			b[i][j] = d[x[j]];
		}
	}

	fill(dp, dp + (1 << m), INF);
	dp[0] = 0;
	for (int i = 0; i < (1 << m); ++i) {
		int u = __builtin_ctz(~i);
		for (int v = u + 1; v < m; ++v) {
			if ((i & (1 << v)) == 0) {
				int j = i ^ (1 << u) ^ (1 << v);
				dp[j] = min(dp[j], dp[i] + b[u][v]);
			}
		}
	}
	printf("%d\n", dp[(1 << m) - 1] == INF ? -1 : dp[(1 << m) - 1]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443102 	May 8, 2011 9:08:03 PM 	watashi 	79D - Password 	GNU C++ 	Accepted 	230 ms 	5600 KB 
