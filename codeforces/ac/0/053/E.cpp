#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 11;
const int LOWER = 0x55555555;
const int UPPER = ~LOWER;
vector<int> e[MAXN];
long long dp[1 << (MAXN + MAXN)];

inline int B(int i, int j) {
	return i << (j + j);
}

int main() {
	int n, m, k, a, b;
	long long ans = 0;

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &a, &b);
		--a;
		--b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[B(1, i) | B(1, j)] = 2;
		}
	}
	m = B(1, n);
	for (int i = 0; i < m; ++i) {
		if (dp[i] == 0) {
			continue;
		}
		dp[i] /= __builtin_popcount(i & LOWER) - __builtin_popcount(i & ~LOWER);
		if (__builtin_popcount(i & LOWER) == n && __builtin_popcount(i & ~LOWER) == n - k) {
			ans += dp[i];
		}
		for (int j = 0; j < n; ++j) {
			if ((i & B(1, j)) != 0) {
				for (vector<int>::const_iterator k = e[j].begin(); k != e[j].end(); ++k) {
					if ((i & B(1, *k)) == 0) {
						dp[i | B(2, j) | B(1, *k)] += dp[i];
					}
				}
			}
		}
	}
//	printf("%lld\n", ans);
	printf("%I64d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//242367 	Jan 8, 2011 9:02:27 PM 	watashi 	53E - Dead Ends 	GNU C++ 	Accepted 	50 ms 	34140 KB 

