#include <cstdio>
#include <algorithm>

using namespace std;

int a[1 << 20];

int main() {
	int n = 1000000;

	for (int i = 0; i < (1 << 20); ++i) {
		a[i] = 123456789 + i * 3;
	}
	random_shuffle(a, a + (1 << 20));

	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}

