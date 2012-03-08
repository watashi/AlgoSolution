#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int n = 100000, m = 100000;

	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", rand() % 1000000000, rand() % 1000000000);
	}
	for (int i = 0; i < m; ++i) {
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		if (a > b) {
			swap(a, b);
		}
		printf("%d %d %d\n", a, b, rand() % 1000000);
	}

	return 0;
}

