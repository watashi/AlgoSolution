#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int x = 1000000000, n = 10000, a, b;

	printf("%d %d\n%d\n", x, x, n);
	for (int i = 0; i < n; ++i) {
		a = rand() % x + 1;
		b = rand() % x + 1;
		if (a > b) {
			swap(a, b);
		}
	//	printf("%d %d\n", a, b);
		printf("%d %d\n", a, a);
	}

	return 0;
}

