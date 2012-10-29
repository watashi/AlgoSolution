#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 19;
// vector<int> e[MAXN];
bool e[MAXN][MAXN];
long long dp[1 << MAXN][MAXN];

int main() {
	int n, m, a, b;
	long long ans;

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a;
		--b;
		e[a][b] = e[b][a] = true;
		dp[(1 << a) ^ (1 << b)][max(a, b)] = 1;
	}

	ans = 0;
	for (int i = 1; i < (1 << n); ++i) {
		int k = __builtin_ctz(i);
		for (int j = k + 1; j < n; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			if (e[j][k]) {
				ans += dp[i][j];
			}
			for (int jj = k + 1; jj < n; ++jj) {
				if (e[j][jj] && (i & (1 << jj)) == 0) {
					dp[i ^ (1 << jj)][jj] += dp[i][j];
				}
			}
		}
	}
	cout << (ans - m) / 2 << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//275635 	Feb 5, 2011 5:05:19 PM 	watashi 	11D - A Simple Task 	GNU C++ 	Accepted 	660 ms 	79300 KB 
