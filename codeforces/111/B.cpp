#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int main() {
	int n, x, y, z;
	static int t[MAXN];

	scanf("%d", &n);
	fill(t, t + MAXN, -1);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", &x, &y);
		z = 0;
		for (int j = 1; j * j <= x; ++j) {
			if (x % j != 0) {
				continue;
			}
			if (y == 0 || t[j] < i - y) {
				++z;
			}
			t[j] = i;
			int k = x / j;
			if (k == j) {
				continue;
			}
			if (y == 0 || t[k] < i - y) {
				++z;
			}
			t[k] = i;
		}
		printf("%d\n", z);
	}

	return 0;
}

