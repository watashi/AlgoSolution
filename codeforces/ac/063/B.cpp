#include <cstdio>

int main() {
	int n, m, a, c[128];

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		c[i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		++c[a];
	}

	a = 0;
	while (c[m] < n) {
		++a;
		for (int i = m - 1; i >= 1; --i) {
			if (c[i] > 0) {
				++c[i + 1];
				--c[i];
			}
		}
	}
	printf("%d\n", a);

	return 0;
}

