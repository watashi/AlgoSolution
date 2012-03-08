// CPP - Chinese Postman Problem

#include <queue>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 16;
const int INF = 1000000007;

int w[MAXN][MAXN], d[MAXN];
int dp[1 << MAXN];

int main() {
	int n, m, a, b, c, s;

	scanf("%d%d", &n, &m);
	fill(w[0], w[n], INF);
	s = 0;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a, &b, &c);
		++d[--a];
		++d[--b];
		w[a][b] = w[b][a] = min(w[a][b], c);
		s += c;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		// if (w[0][i] == INF) {	// WA9
		if (d[i] > 0 && w[0][i] == INF) {
			puts("-1");
			return 0;
		}
	}

	fill(dp, dp + (1 << n), INF);
	a = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] & 1) {
			a ^= 1 << i;
		}
	}
	dp[a] = s;

	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(-dp[a], a));
	while (!pq.empty()) {
		s = -pq.top().first;
		a = pq.top().second;
		pq.pop();
		if (s != dp[a]) {
			continue;
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				b = a ^ (1 << i) ^ (1 << j);
				if (dp[b] > dp[a] + w[i][j]) {
					dp[b] = dp[a] + w[i][j];
					pq.push(make_pair(-dp[b], b));
				}
			}
		}
	}
	printf("%d\n", dp[0]);

	return 0;
}

/*
WA9
Input
5 0
Output
-1
Answer
0
*/

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//283394 	Feb 12, 2011 6:39:11 PM 	watashi 	21D - Traveling Graph 	GNU C++ 	Accepted 	50 ms 	2000 KB 
