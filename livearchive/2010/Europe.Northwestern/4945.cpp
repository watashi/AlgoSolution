// GOOD PROBLEM

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 1024;
const int INF = 1000000000;

PII a[MAXN], dp[MAXN][MAXN];

bool pr(const PII& lhs, const PII& rhs) {
	return lhs.second != rhs.second ? lhs.second > rhs.second : lhs.first < rhs.first;
}

int main() {
	int re, n, x, y, s, diff;
	char who[80];
	PII t;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		scanf("%s", who);
		diff = (strcmp(who, "Petra") == 0 ? 0 : 1);
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &a[i].second, &a[i].first);
		}
		sort(a, a + n, pr);
//		for (int i = 0; i < n; ++i) {
//			printf("> %d %d\n", a[i].first, a[i].second);
//		}

		// x: Jan; y: Petra;
		x = (n + diff) / 2;
		y = n - x;

		dp[1][0] = make_pair(a[0].first, 0);
		for (int j = 1; j < n; ++j) {
			dp[1][j] = make_pair(a[j].first, dp[1][j - 1].second + a[j - 1].second);
		}
		for (int j = 0; j < n; ++j) {
			if (j + 1 - 1 < 1 - diff) {
				dp[1][j] = make_pair(-INF, -INF);
			} else {
//				printf("[%d][%d] = (%d, %d)\n", 1, j, dp[1][j].first, dp[1][j].second);
			}
		}
		for (int i = 2; i <= x; ++i) {
			t = make_pair(-INF, -INF);
			s = 0;
			for (int j = 0; j < n; ++j) {
				// Jan = i
				// Petra = j + 1 - i
				if (j + 1 - i < i - diff) {
					dp[i][j] = make_pair(-INF, -INF);
				} else {
					dp[i][j] = t;
					dp[i][j].first += a[j].first;
					dp[i][j].second += s;
				}
				s += a[j].second;
				t = max(t, make_pair(dp[i - 1][j].first, dp[i - 1][j].second - s));
//				if (dp[i][j].first >= 0) {
//					printf("[%d][%d] = (%d, %d)\n", i, j, dp[i][j].first, dp[i][j].second);
//				}
			}
		}
		t = make_pair(0, 0);
		s = 0;
		for (int j = n - 1; j >= 0; --j) {
			dp[x][j].second += s;
			t = max(t, dp[x][j]);
			s += a[j].second;
		}
		if (diff == 0 && n == 1) {
			t = make_pair(0, a[0].second);
		}
		printf("%d %d\n", t.second, t.first);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714968  	2011-01-04 03:58:56 	Accepted	0.969	8600	26909	C++	4945 - Free Goodies
/*
id => 1174284
pid => 4945
pname => Free Goodies
status => Accepted
lang => C++
time => 0.342
date => 2012-12-14 17:49:14
*/
