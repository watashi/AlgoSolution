#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const double INF = 1e100;

double x[MAXN], y[MAXN];
double d[MAXN][MAXN];

double gao(int n, int a, int b, vector<int>& ret) {
	static int pre[MAXN][MAXN];
	static double dp[MAXN][MAXN];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			int k = max(i, j) + 1;
			if (k != b && dp[k][j] > dp[i][j] + d[i][k]) {
				dp[k][j] = dp[i][j] + d[i][k];
				pre[k][j] = i;
			}
			if (k != a && dp[i][k] > dp[i][j] + d[j][k]) {
				dp[i][k] = dp[i][j] + d[j][k];
				pre[i][k] = -1 - j;
			}
		}
	}

	double ans = INF;
	for (int i = 0; i < n; ++i) {
		if (ans > dp[n - 1][i] + d[n - 1][i]) {
			ans = dp[n - 1][i] + d[n - 1][i];
			a = n - 1;
			b = i;
		}
	}
	vector<int> tmp;
	ret.clear();
	ret.push_back(a);
	tmp.push_back(b);
	while (a > 0 || b > 0) {
//		printf("%d %d %lf (%lf)\n", a, b, dp[a][b], ans);
		if (pre[a][b] >= 0) {
			ret.push_back(pre[a][b]);
			a = pre[a][b];
		} else {
			tmp.push_back(-1 - pre[a][b]);
			b = -1 - pre[a][b];
		}
	}
	reverse(ret.begin(), ret.end());
	ret.insert(ret.end(), tmp.begin(), tmp.end());
	return ans;
}

int main() {
	int ri = 0, n, b1, b2;
	double ret;
	vector<int> how;

	while (scanf("%d%d%d", &n, &b1, &b2) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x[i], &y[i]);
			for (int j = 0; j <= i; ++j) {
				d[i][j] = d[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
			}
		}
		ret = gao(n, b1, b2, how);
		if (how[1] != 1) {
			reverse(how.begin(), how.end());
		}
		printf("Case %d: %.2lf\n", ++ri, ret);
		for (int i = 0; i < (int)how.size(); ++i) {
			printf("%d%c", how[i], i == (int)how.size() - 1 ? '\n' : ' ');
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805864 	4791 	The Islands 	Accepted 	C++ 	0.020 	2011-05-23 14:04:43
/*
id => 1174052
pid => 4791
pname => The Islands
status => Accepted
lang => C++
time => 0.022
date => 2012-12-14 17:15:45
*/
