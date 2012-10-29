#include <set>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

char s[128][128];

void impossible() {
	puts("IMPOSSIBLE");
	exit(0);
}

void gao(int x1, int y1, int x2, int y2) {
	char c = '?';
	set<int> b;
	for (int i = x1; i <= x2; ++i) {
		b.insert(s[i][y1 - 1]);
		b.insert(s[i][y2 + 1]);
	}
	for (int j = y1; j <= y2; ++j) {
		b.insert(s[x1 - 1][j]);
		b.insert(s[x2 + 1][j]);
	}
	for (char k = 'a'; k <= 'z'; ++k) {
		if (b.count(k) == 0) {
			c = k;
			break;
		}
	}
	for (int i = x1; i <= x2; ++i) {
		for (int j = y1; j <= y2; ++j) {
			s[i][j] = c;
		}
	}
}

int main() {
	int n, m, a, b, c;

	scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	if (n % 2 != 0 && m % 2 != 0) {
		impossible();
	}
	if (n % 2 != 0) {
		if (a * 2 < m) {
			impossible();
		} else {
			a -= m / 2;
		}
		for (int j = 1; j <= m; j += 2) {
			gao(1, j, 1, j + 1);
		}
	}
	if (m % 2 != 0) {
		if (b * 2 < n) {
			impossible();
		} else {
			b -= n / 2;
		}
		for (int i = 1; i <= n; i += 2) {
			gao(i, 1, i + 1, 1);
		}
	}
	for (int i = 1 + n % 2; i <= n; i += 2) {
		for (int j = 1 + m % 2; j <= m; j += 2) {
			if (a >= 2) {
				a -= 2;
				gao(i, j, i, j + 1);
				gao(i + 1, j, i + 1, j + 1);
			} else if (b >= 2) {
				b -= 2;
				gao(i, j, i + 1, j);
				gao(i, j + 1, i + 1, j + 1);
			} else if (c >= 1) {
				c -= 1;
				gao(i, j, i + 1, j + 1);
			} else {
				impossible();
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		puts(s[i] + 1);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309225 	Feb 28, 2011 11:18:25 AM 	watashi 	26C - Parquet 	GNU C++ 	Accepted 	30 ms 	1400 KB
