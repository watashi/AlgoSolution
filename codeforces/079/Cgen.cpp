#include <cstdio>
#include <cstdlib>

int main() {
	int n = 100000, k = 10;

	for (int i = 0; i < n; ++i) {
		putchar(rand() % 2 == 0 ? '0' : '1');
	}
	printf("\n%d\n", k);
	puts("010");
	puts("101");
	puts("000001");
	puts("100000");
	puts("100001");
	puts("0123456789");
	puts("9876543234");
	puts("1101110111");
	puts("1111111111");
	puts("0000000000");

	return 0;
}


