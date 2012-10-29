#include <cstdio>
#include <cstdlib>

int main() {
	int n = 50, m = 250000, l = 5000;
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		printf("%d", l);
		for (int j = 0; j < l; ++j) {
			printf(" %d", rand() % 1998 - 1000);
		}
		puts("");
	}
	for (int i = 0; i < m; ++i) {
		printf("%d%c", 1 + rand() % n, i == m - 1 ? '\n' : ' ');
	}
	return 0;
}

