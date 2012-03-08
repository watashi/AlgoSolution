#include <cstdio>

int main() {
	printf("%d\n", 100000);
	for (int i = 0; i < 50000; ++i) {
		printf("%d ", 10000);
	}
	for (int i = 99998; i >= 50000; --i) {
		printf("%d ", i);
	}
	printf("%d\n", 2);
	for (int i = 0; i < 50000; ++i) {
		printf("%d ", 9999);
	}
	for (int i = 99998; i >= 50000; --i) {
		printf("%d ", 50000 + 99999 - i);
	}
	printf("%d\n", 3);

	return 0;
}

