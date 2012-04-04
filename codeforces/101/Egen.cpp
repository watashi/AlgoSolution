#include <cstdio>
#include <cstdlib>

int main() {
	int r = 20000, c = 20000, p = 65536;

	printf("%d %d %d\n", r, c, p);
	for (int i = 0; i < r; ++i) {
		printf("%d%c", rand() % 20000, i == r - 1 ? '\n' : ' ');
	}
	for (int i = 0; i < c; ++i) {
		printf("%d%c", rand() % 20000, i == c - 1 ? '\n' : ' ');
	}

	return 0;
}

