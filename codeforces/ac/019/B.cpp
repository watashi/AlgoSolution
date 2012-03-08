#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4096;
const long long INF = 12345678987654321LL;

long long dp[MAXN];

int main() {
	int n, t;
	long long c;

	cin >> n;
	dp[0] = 0;
	fill(dp + 1, dp + 1 + n, INF);
	for (int i = 0; i < n; ++i) {
		cin >> t >> c;
		++t;
		for (int i = n + t; i > n; --i) {
			dp[n] = min(dp[n], dp[i - t] + c);
		}
		for (int i = n; i >= t; --i) {
			dp[i] = min(dp[i], dp[i - t] + c);
		}
	}
	cout << dp[n] << endl;

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//300767 	Feb 23, 2011 4:29:21 PM 	watashi 	19B - Checkout Assistant 	GNU C++ 	Accepted 	50 ms 	1400 KB
