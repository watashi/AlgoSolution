#include <cstdio>

int n, r[32], a[32][32];

bool gao(int i, int j) {
	if (i == n) {
		return true;
	} else if (j == n) {
		return gao(i + 1, i + 2);
	} else if (i + j < n) {
		return gao(i, j + 1);
	} else {
		int mask = r[i] | r[j];
		for (int k = 1; k < n; ++k) {
			if ((mask & (1 << k)) == 0) {
				r[i] ^= 1 << k;
				r[j] ^= 1 << k;
				a[i][j] = a[j][i] = k;
				if (gao(i, j + 1)) {
					return true;
				}
				r[i] ^= 1 << k;
				r[j] ^= 1 << k;
			}
		}
		return false;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i + j < n && i != j) {
				a[i][j] = i + j;
				r[i] |= 1 << i + j;
				r[j] |= 1 << i + j;
			}
		}
	}
	if (gao(0, 1)) {
		puts("OK");
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%2d ", a[i][j]);
		}
		puts("");
	}

	return 0;
}

// comment at cf: http://www.cut-the-knot.org/arithmetic/latin2.shtml
