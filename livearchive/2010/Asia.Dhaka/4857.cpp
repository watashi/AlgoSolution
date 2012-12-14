// GOOD PROBLEM
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int dp[MAXN][MAXN];

int main() {
	int re, n, m;
	int a[MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		for (int i = n; i > 0; --i) {
			dp[i][i] = 1;
			for (int j = i + 1; j <= n; ++j) {
				dp[i][j] = (a[j] == a[i] ? dp[i][j - 1] : 65536);
				for (int k = i + 1; k <= j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
				}
			}
		}
		printf("Case %d: %d\n", ri, dp[1][n]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714974  	2011-01-04 04:11:32 	Accepted	1.324	464	26909	C++	4857 - Halloween Costumes

/*
id => 1174070
pid => 4857
pname => Halloween Costumes
status => Accepted
lang => C++
time => 0.269
date => 2012-12-14 17:18:33
*/
