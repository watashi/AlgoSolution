#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 128;

int p[MAXN];
bool w[MAXN][MAXN];

int main() {
	int n, d;
	bool flag;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		--p[i];
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &d);
		w[i][i] = true;
		if (i - d >= 0) {
			w[i][i - d] = w[i - d][i] = true;
		}
		if (i + d < n) {
			w[i][i + d] = w[i + d][i] = true;
		}
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				w[i][j] |= w[i][k] && w[k][j];
			}
		}
	}
	flag = true;
	for (int i = 0; flag && i < n; ++i) {
		flag &= w[i][p[i]];
	}
	puts(flag ? "YES" : "NO");

	return 0;
}

// 新手上路 IDEA ? (改成有向的)
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309470 	Feb 28, 2011 5:23:40 PM 	watashi 	28B - pSort 	GNU C++ 	Accepted 	30 ms 	1300 KB
