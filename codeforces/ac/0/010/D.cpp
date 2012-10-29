#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 512;

int a[MAXN], b[MAXN];
int dp[MAXN][MAXN];
pair<int, int> pre[MAXN][MAXN];
pair<int, pair<int, int> > lis[MAXN];

void dump(int x, int y) {
	if (x >= 0 && y >= 0 && dp[x][y] > 0) {
		dump(pre[x][y].first, pre[x][y].second);
		printf("%d ", a[x]);
	}
}

int main() {
	int n, m, x, y;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int j = 0; j < m; ++j) {
		scanf("%d", &b[j]);
	}
	fill(lis, lis + m, make_pair(0, make_pair(-1, -1)));

	x = y = 0;
	for (int i = 0; i < n; ++i) {
		pair<int, pair<int, int> > k = make_pair(0, make_pair(-1, -1));
		for (int j = 0; j < m; ++j) {
			if (b[j] < a[i]) {
				k = max(k, lis[j]);
			}
			if (a[i] != b[j]) {
				dp[i][j] = 0;
				pre[i][j] = make_pair(-1, -1);
			} else {
				dp[i][j] = k.first + 1;
				pre[i][j] = k.second;
				lis[j] = make_pair(dp[i][j], make_pair(i, j));
			}
			if (dp[i][j] > dp[x][y]) {
				x = i;
				y = j;
			}
		}
	}

	printf("%d\n", dp[x][y]);
	dump(x, y);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//444073 	May 10, 2011 2:41:39 AM 	watashi 	10D - LCIS 	GNU C++ 	Accepted 	30 ms 	4400 KB 
