#include <cstdio>
#include <algorithm>

using namespace std;

int a[10][10], r[10][10], c[10][10];

int rowval(int i, int j) {
	int ret = 1;
	for (int k = j - 1; a[i][k] > 0; --k) {
		++ret;
	}
	for (int k = j + 1; a[i][k] > 0; ++k) {
		++ret;
	}
	return ret;
}

int colval(int i, int j) {
	int ret = 1;
	for (int k = i - 1; a[k][j] > 0; --k) {
		++ret;
	}
	for (int k = i + 1; a[k][j] > 0; ++k) {
		++ret;
	}
	return ret;
}

int main() {
	int n, v, w;
	bool over, cont;

	while (scanf("%d", &n) != EOF && n > 0) {
		fill(a[0], a[1], -1);
		fill(a[1], a[10], 0);
		over = false;

		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &v, &w);
			if (over) {
				continue;
			}
			a[8][w] = v;
			cont = true;
			while (cont) {
				while (cont) {
					cont = false;
					for (int i = 1; i <= 7; ++i) {
						for (int j = 1; j <= 7; ++j) {
							if (a[i][j] == 0 && a[i + 1][j] > 0) {
								a[i][j] = a[i + 1][j];
								a[i + 1][j] = 0;
								cont = true;
							}
						}
					}
				}
				for (int j = 1; j <= 7; ++j) {
					if (a[8][j] > 0) {
						over = true;
					}
				}
				for (int i = 1; i <= 7; ++i) {
					for (int j = 1; j <= 7; ++j) {
						r[i][j] = rowval(i, j);
						c[i][j] = colval(i, j);
					}
				}
				for (int i = 1; i <= 7; ++i) {
					for (int j = 1; j <= 7; ++j) {
						if (a[i][j] == r[i][j] || a[i][j] == c[i][j]) {
							a[i][j] = 0;
							cont = true;
						}
					}
				}
			}
		}

		if (over) {
			puts("Game Over!");
		} else {
			for (int i = 7; i >= 1; --i) {
				for (int j = 1; j <= 7; ++j) {
					putchar(a[i][j] == 0 ? '#' : '0' + a[i][j]);
				}
				puts("");
			}
		}
		puts("");
	}

	return 0;
}
//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//870185 	5048 	Drop7 	Accepted 	C++ 	0.020 	2011-08-30 06:14:10
/*
id => 1174147
pid => 5048
pname => Drop7
status => Accepted
lang => C++
time => 0.018
date => 2012-12-14 17:30:10
*/
