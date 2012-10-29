#include <cstdio>

using namespace std;

const int MAXN = 128;
int type[MAXN][MAXN];

const char* pat[6] = {"#//.", "\\#.\\", "\\.#\\", ".//#", "....", "####"};

int main() {
	int n, m, a, b, c, k, x, y;

	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &a, &b, &c);
	k = 0;
	for (int i = 0; i < a; ++i, ++k) {
		type[k / m][k % m] = 5;
	}
	y = k % m;
	for (int i = 0; i < m; ++i, ++k) {
		type[k / m][k % m] = (((k % m - y) % 2 == 0) ^ (k % m < y)) ? 0 : 1;
	}
	for (int i = 0; i < b; ++i, ++k) {
		type[k / m][k % m] = 4;
	}
	for (int i = m; i < c; ++i, ++k) {
		for (int j = 0; j < 4; ++j) {
			x = k / m;
			y = k % m;
			if ((x == 0 || ((type[x - 1][y] ^ j) & 2) != 0) &&
				(y == 0 || ((type[x][y - 1] ^ j) & 1) != 0)) {
				type[k / m][k % m] = j;
				break;
			}
		}
	}

	for (int i = 0; i < n + n; ++i) {
		for (int j = 0; j < m + m; ++j) {
			putchar(pat[type[i / 2][j / 2]][i % 2 * 2 + j % 2]);
		}
		puts("");
	}

	return 0;
}

// c >= m !!!
// WA8 (swap(pat[4], pat[5]))
// so easy
//
//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218930 	Dec 13, 2010 9:11:01 PM 	watashi 	H - Black and White 	GNU C++ 	Accepted 	30 ms 	1360 KB
