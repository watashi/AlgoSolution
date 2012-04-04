#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dz[] = "SENW";

char a[MAXN][MAXN];
int d[4][MAXN][MAXN];

int main() {
	int r, c, n, m, p;
	int x[26], y[26];
    char z;

	scanf("%d%d", &r, &c);
	fill(x, x + 26, -1);
	fill(y, y + 26, -1);
	for (int i = 0; i < r; ++i) {
		scanf("%s", a[i]);
		for (int j = 0; j < c; ++j) {
			if (isupper(a[i][j])) {
				x[a[i][j] - 'A'] = i;
				y[a[i][j] - 'A'] = j;
				a[i][j] = '.';
			}
		}
	}

	for (int k = 0; k < 4; ++k) {
		fill(d[k][0], d[k][r], -1);
		for (int i = k < 2 ? r - 1 : 0; 0 <= i && i < r; i += k < 2 ? -1 : 1) {
			for (int j = k < 2 ? c - 1 : 0; 0 <= j && j < c; j += k < 2 ? -1 : 1) {
				if (a[i][j] == '.') {
					d[k][i][j] = d[k][i + dx[k]][j + dy[k]] + 1;
				}
			}
		}
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf(" %c%d", &z, &m);
		p = find(dz, dz + 4, z) - dz;
		for (int j = 0; j < 26; ++j) {
			if (x[j] == -1 || y[j] == -1) {
			} else if (m > d[p][x[j]][y[j]]) {
				x[j] = y[j] = -1;
			} else {
				x[j] += dx[p] * m;
				y[j] += dy[p] * m;
			}
		}
	}

	z = '.';
	for (int i = 0; i < 26; ++i) {
		if (x[i] != -1 && y[i] != -1) {
			putchar('A' + i);
			z = '#';
		}
	}
	if (z == '.') {
		puts("no solution");
	}

	return 0;
}

