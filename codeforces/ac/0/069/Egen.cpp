#include <cstdio>
#include <cstdlib>

int main() {
	int n = 100000, m = 50000;

	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		printf("%d\n", rand() % 100000);
	}

	return 0;
}

