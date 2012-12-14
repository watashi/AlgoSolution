#include <cstdio>

using namespace std;

const int MOD = 1000000;
const int MAXN = 1024;
int dp[MAXN][MAXN];

int main() {
	int n;
	
	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		for (int j = i; j >= 1; --j) {
			dp[i][j] = dp[i][j + 1] + dp[i - 1][j - 1];
			dp[i][j] %= MOD;
		}
		dp[i][0] = dp[i][1];
	}
	while (scanf("%d", &n) != EOF && n > 0) {
		printf("%d\n", dp[n][0]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714865  	2011-01-03 16:50:38 	Accepted	0.025	Minimum	26909	C++	4871 - Skyline
/*
id => 1174299
pid => 4871
pname => Skyline
status => Accepted
lang => C++
time => 0.026
date => 2012-12-14 17:51:17
*/
