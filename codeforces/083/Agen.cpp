#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {
	int n = 100000;

	printf("%d\n", n);
	for (int i = 0; i < n; ++i) {
		printf("%d%c", abs(i - 50000) < 40000 ? 12345 : i / 4, i == n - 1 ? '\n' : ' ');
	}
}

