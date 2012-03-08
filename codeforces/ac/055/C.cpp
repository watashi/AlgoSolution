#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k, x, y, z;

	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d%d", &x, &y);
		z = min(min(x - 1, n - x), min(y - 1, m - y));
		if (z <= 4) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}

