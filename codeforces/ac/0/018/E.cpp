#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 1 << 20;

int dp[512][26][26], _dp[26][26];
pair<int, int> pre[512][26][26], _pre[26][26];


#define update(dj, dk)\
	if (0 <= j + dj &&\
		j + dj < 26 &&\
		0 <= k + dk &&\
		k + dk < 26 &&\
		_dp[j][k] > _dp[j + dj][k + dk]) {\
		_dp[j][k] = _dp[j + dj][k + dk];\
		_pre[j][k] = _pre[j + dj][k + dk];\
	}

#define _update(dj, dk)\
	if (0 <= j + dj &&\
		j + dj < 26 &&\
		0 <= k + dk &&\
		k + dk < 26 &&\
		dp[i][j + dj][k + dk] > _dp[j][k]) {\
		dp[i][j + dj][k + dk] = _dp[j][k];\
		pre[i][j + dj][k + dk] = _pre[j][k];\
	}

#define gao(dj, dk)\
	for (int j = dj > 0 ? 0 : 25; 0 <= j && j < 26; j += dj) {\
		for (int k = dk > 0 ? 0 : 25; 0 <= k && k < 26; k += dk) {\
			_dp[j][k] = dp[i - 1][j][k];\
			_pre[j][k] = make_pair(j, k);\
			update(-dj, 0);\
			update(0, -dk);\
			_update(dj, dk);\
		}\
	}

void print(int n, int m, int x, int y) {
	if (n > 1) {
		print(n - 1, m, pre[n][x][y].first, pre[n][x][y].second);
	}
	for (int i = 0; i < m; ++i) {
		if (i % 2 == 0) {
			putchar('a' + x);
		} else {
			putchar('a' + y);
		}
	}
	puts("");
}

int main() {
	int n, m, x, y;
	char s[512];
	int c[2][26];

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		fill(c[0], c[2], 0);
		for (int j = 0; j < m; ++j) {
			++c[j % 2][s[j] - 'a'];
		}
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {
				dp[i][j][k] = INF;
			}
		}
		gao(1, 1);
		gao(1, -1);
		gao(-1, 1);
		gao(-1, -1);
		for (int j = 0; j < 26; ++j) {
			for (int k = 0; k < 26; ++k) {
				dp[i][j][k] += (m + 1) / 2 - c[0][j] + m / 2 - c[1][k];
			}
			dp[i][j][j] = INF;
		}
	}

	x = 0;
	y = 0;
	for (int j = 0; j < 26; ++j) {
		for (int k = 0; k < 26; ++k) {
			if (dp[n][j][k] < dp[n][x][y]) {
				x = j;
				y = k;
			}
		}
	}
	printf("%d\n", dp[n][x][y]);
	print(n, m, x, y);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//213129 	Dec 10, 2010 5:15:25 PM 	watashi 	E - Flag 2 	GNU C++ 	Accepted 	50 ms 	5396 KB 
