// GOOD PROBLEM

#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 21;
const int INF = 1000000000;

int n, e[MAXN];
int dp[1 << MAXN], q[1 << MAXN];//, how[1 << MAXN];

inline int _next(int mask) {
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			ret |= e[i];
		}
	}
	return ret;
}

void gao() {
	bool flag = false;
	int mask, next;
	int begin = 0, end = 0;
	
	fill(dp, dp + (1 << n), -1);
	mask = (1 << n) - 1;
	q[end++] = mask;
	dp[mask] = 0;
	while (begin < end && dp[0] == -1) {
		mask = q[begin++];
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				next = _next(mask ^ (1 << i));
				if (dp[next] == -1) {
					dp[next] = dp[mask] + 1;
					q[end++] = next;
				}
			}
		}
	}

	if (dp[0] == -1) {
		puts("Impossible");
		return;
	} else {
		printf("%d:", dp[0]);
	}

	while (end > 0) {
		mask = q[--end];
		if (dp[mask] == dp[0]) {
			dp[mask] = mask == 0 ? dp[0] : -1;
		} else {
			flag = false;
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					next = _next(mask ^ (1 << i));
					if (dp[next] == dp[mask] + 1) {
						flag = true;
						break;
					}
				}
			}
			if (!flag) {
				dp[mask] = -1;
			}
		}
	}

	while (mask > 0) {
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				next = _next(mask ^ (1 << i));
				if (dp[next] == dp[mask] + 1) {
					printf(" %d", i);
					mask = next;
					break;
				}
			}
		}
	}
	puts("");	
}

int main() {
	int m, a, b;

	while (scanf("%d%d", &n, &m) != EOF && !(n == 0 && m == 0)) {
		for (int i = 0; i < n; ++i) {
			e[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			if (a < 0 || a >= n || b < 0 || b >= n || a == b) {
				throw 1;
			}
			e[a] |= 1 << b;
			e[b] |= 1 << a;
		}
		gao();
	}

	return 0;
}

// 记忆化会WA；建边拓扑会TLE
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714957  	2011-01-04 03:40:12 	Accepted	1.395	16784	26909	C++	4959 - Jumping monkey

/*
id => 1174213
pid => 4959
pname => Jumping monkey
status => Accepted
lang => C++
time => 1.368
date => 2012-12-14 17:39:38
*/
