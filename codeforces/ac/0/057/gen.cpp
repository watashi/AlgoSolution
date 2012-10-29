#include <cstdio>

int main() {
	printf("100000 100000 100\n");
	for (int i = 0; i < 100000; ++i) {
		printf("%d %d 3\n", i / 2 + 1, i + 1);
	}
	for (int i = 0; i < 100; ++i) {
		printf("%d\n", i * 500 + 1);
	}
	return 0;
}

