#include <cstdio>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int INF = 1000000007;

int n, a[MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int gao(int i, int j) {
	int& ret = dp[i][j];
	if (ret != -1) {
		return ret;
	} else if (i >= n) {
		return ret = 0;
	} else if (j >= n) {
		return ret = a[i];
	} else if (j + 1 >= n) {
		return ret = max(a[i], a[j]);
	} else {
		ret = INF;
		if (ret > max(a[i], a[j]) + gao(j + 1, j + 2)) {
			ret = max(a[i], a[j]) + gao(j + 1, j + 2);
			pre[i][j] = 0;
		}
		if (ret > max(a[i], a[j + 1]) + gao(j, j + 2)) {
			ret = max(a[i], a[j + 1]) + gao(j, j + 2);
			pre[i][j] = 1;
		}
		if (ret > max(a[j], a[j + 1]) + gao(i, j + 2)) {
			ret = max(a[j], a[j + 1]) + gao(i, j + 2);
			pre[i][j] = 2;
		}
		return ret;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	memset(dp, 0xff, sizeof(dp));
	printf("%d\n", gao(0, 1));
	
	vector<pair<int, int> > ans;
	for (int i = 0, j = 1; ; ) {
		if (i >= n) {
			break;
		} else if (j >= n) {
			ans.push_back(make_pair(i, -1));
			break;
		} else if (j + 1 >= n) {
			ans.push_back(make_pair(i, j));
			break;
		} else {
			switch (pre[i][j]) {
				case 0:
					ans.push_back(make_pair(i, j));
					i = j + 1;
					j = j + 2;
					break;
				case 1:
					ans.push_back(make_pair(i, j + 1));
					i = j;
					j = j + 2;
					break;
				case 2:
					ans.push_back(make_pair(j, j + 1));
					i = i;
					j = j + 2;
					break;
			}
		}
	}
	for (int i = 0; i < (int)ans.size(); ++i) {
		if (ans[i].second == -1) {
			printf("%d\n", ans[i].first + 1);
		} else {
			printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
		}
	}

	return 0;
}

