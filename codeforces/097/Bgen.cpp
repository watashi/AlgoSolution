#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int n = 10000;
	int m = 100000000;

	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d %d\n", -rand() % m, -rand() % m);
	}

	return 0;
}

