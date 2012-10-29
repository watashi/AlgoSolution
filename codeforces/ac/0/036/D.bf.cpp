#include <cstdio>

const int MAXN = 72;

bool f[MAXN][MAXN];

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < MAXN; ++i) {
		printf("%3d: ", i);
		for (int j = 0; j < MAXN; ++j) {
			f[i][j] =
				i > 0 && !f[i - 1][j] ||
				j > 0 && !f[i][j - 1] ||
				i >= k && j >= k && !f[i - k][j - k];
			putchar(f[i][j] ? 'Y' : 'N');
		}
		puts("");
	}
	return 0;
}

