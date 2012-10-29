#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1023;
const int INF = 1 << 20;
int a[MAXN][MAXN], dp[MAXN][MAXN], pre[MAXN][MAXN];

template<int R>
inline int scale(int x) {
	if (x == 0) {
		return INF;
	} else {
		int y = 0;
		while (x % R == 0) {
			x /= R;
			++y;
		}
		return y;
	}
}

template<int R>
pair<int, string> solve(int n, int a[MAXN][MAXN]) {
	dp[0][0] = scale<R>(a[0][0]);
	for (int i = 1; i < n; ++i) {
		dp[i][0] = scale<R>(a[i][0]) + dp[i - 1][0];
		pre[i][0] = 0;
		dp[0][i] = scale<R>(a[0][i]) + dp[0][i - 1];
		pre[0][i] = 1;
	}
	
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < n; ++j) {
			if (dp[i - 1][j] < dp[i][j - 1]) {
				dp[i][j] = dp[i - 1][j];
				pre[i][j] = 0;
			} else {
				dp[i][j] = dp[i][j - 1];
				pre[i][j] = 1;
			}
			dp[i][j] += scale<R>(a[i][j]);
		}
	}
	
	string ret;
	for (int i = n - 1, j = n - 1; i > 0 || j > 0; ) {
		if (pre[i][j] == 0) {
			ret += 'D';
			--i;
		} else {
			ret += 'R';
			--j;
		}
	}
	reverse(ret.begin(), ret.end());

	return make_pair(dp[n - 1][n - 1], ret);
}

int main() {
	int n, x, y;
	pair<int, string> ans;

	scanf("%d", &n);
	x = -1;
	y = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 0) {
				x = i;
				y = j;
			}
		}
	}
	ans = min(solve<2>(n, a), solve<5>(n, a));
	if (x != -1 && ans.first > 1) {
		ans.first = 1;
		ans.second = "";
		ans.second.append(x, 'D');
		ans.second.append(y, 'R');
		ans.second.append(n - 1 - x, 'D');
		ans.second.append(n - 1 - y, 'R');
	}
	printf("%d\n%s\n", ans.first, ans.second.c_str());

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//255428 	Jan 20, 2011 9:40:20 AM 	watashi 	2B - The least round way 	GNU C++ 	Accepted 	480 ms 	13600 KB 

