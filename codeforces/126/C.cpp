#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 2048;

int gao(int n, bool a[MAXN][MAXN]) {
	static bool u[MAXN][MAXN], r[MAXN][MAXN];
	int ret = 0;

	fill(u[0], u[n], false);
	fill(r[0], r[n], false);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			a[i][j] ^= u[i][j] ^ r[i][j];
			u[i - 1][j] ^= u[i][j];
			r[i][j + 1] ^= r[i][j];
			if (a[i][j]) {
			//	printf("+%d %d\n", i, j);
				++ret;
				u[i - 1][j] ^= true;
				r[i][j + 1] ^= true;
			}
		}
		a[i][i] ^= u[i][i] ^ r[i][i];
	}

	return ret;
}

int main() {
	int n, ans;
	static char s[MAXN][MAXN];
	static bool a[MAXN][MAXN];

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s[i]);
		for (int j = 0; j < n; ++j) {
			a[i][j] = s[i][j] == '1';
		}
	}

	ans = 0;
	ans += gao(n, a);
	fprintf(stderr, "ans = %d\n", ans);
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 0; j < i; ++j) {
			a[i][j] = a[j][i];
		}
	}
	ans += gao(n, a);
	fprintf(stderr, "ans = %d\n", ans);
	for (int i = 0; i < n; ++i) {
		if (a[i][i]) {
	//		printf("++ %d\n", i);
			++ans;
		}
	}
	printf("%d\n", ans);

	return 0;
}

