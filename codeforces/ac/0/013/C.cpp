#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 5050;

int a[MAXN], b[MAXN];
long long dp[MAXN];

int main() {
	int n, m;
	long long t;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	copy(a, a + n, b);
	sort(b, b + n);
	m = unique(b, b + n) - b;
	fill(dp, dp + m, 0);

	for (int i = 0; i < n; ++i) {
		t = dp[0];
		for (int j = 0; j < m; ++j) {
			t = min(t, dp[j]);
			dp[j] = t + llabs(b[j] - a[i]);
		}
	}
	printf("%I64d\n", *min_element(dp, dp + m));

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//276036 	Feb 6, 2011 11:33:22 AM 	watashi 	13C - Sequence 	GNU C++ 	Accepted 	130 ms 	1400 KB 
