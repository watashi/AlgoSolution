#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

struct S {
	int x, y, t;
	double p;
} s[MAXN];

bool operator<(const S& lhs, const S& rhs) {
	return lhs.t < rhs.t;
}

long long sqr(long long x) {
	return x * x;
}

int main() {
	int n;
	double dp[MAXN], ans;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%lf", &s[i].x, &s[i].y, &s[i].t, &s[i].p);
	}
	sort(s, s + n);

	ans = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = 0;
		for (int j = 0; j < i; ++j) {
			if (sqr(s[i].x - s[j].x) + sqr(s[i].y - s[j].y) <= sqr(s[i].t - s[j].t)) {
				dp[i] = max(dp[i], dp[j]);
			}
		}
		dp[i] += s[i].p;
		ans = max(ans, dp[i]);
	}
	printf("%.10lf\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//413774 	Apr 28, 2011 11:30:30 AM 	watashi 	30C - Shooting Gallery 	GNU C++ 	Accepted 	30 ms 	1400 KB 
