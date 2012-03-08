#include <cstdio>

const int MAXN = 128;

int main() {
	int r, c;
	char s[MAXN][MAXN];

	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			bool flag = true;
			for (int k = 0; flag && k < r; ++k) {
				flag &= k == i || s[k][j] != s[i][j];
			}
			for (int k = 0; flag && k < c; ++k) {
				flag &= k == j || s[i][k] != s[i][j];
			}
			if (flag) {
				putchar(s[i][j]);
			}
		}
	}

	return 0;
}
