#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 1024;

int main() {
	int re, n, m, x, y, a[MAXN], c[MAXN];
	bool w[MAXN][MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
		}
		fill(w[0], w[n], false);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				w[a[j]][a[i]] = true;
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			--x;
			--y;
			swap(w[x][y], w[y][x]);
		}

		fill(c, c + n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (w[i][j]) {
					++c[j];
				}
			}
		}

		x = find(c, c + n, 0) - c;
		for (int i = 0; x < n && i < n; ++i) {
			a[i] = x;
			y = n;
			for (int j = 0; j < n; ++j) {
				if (w[x][j]) {
					if (--c[j] == 0) {
						y = j;
					}
				}
			}
			if (i < n - 1) {
				x = y;
			}
		}
		if (x == n) {
			puts("IMPOSSIBLE");
		} else {
			for (int i = 0; i < n; ++i) {
				printf("%d%c", a[i] + 1, i == n - 1 ? '\n' : ' ');
			}
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881083 	4948 	Rankings 	Accepted 	C++ 	0.116 	2011-09-13 09:35:52
/*
id => 1174280
pid => 4948
pname => Rankings
status => Accepted
lang => C++
time => 0.052
date => 2012-12-14 17:48:27
*/
