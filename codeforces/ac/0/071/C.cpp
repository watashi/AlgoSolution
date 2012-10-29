#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
bool a[MAXN], b[MAXN];

int main() {
	int n, t;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &t);
		a[i] = (t > 0);
	}
	for (int i = 1; i * 3 <= n; ++i) {
		if (n % i != 0) {
			continue;
		}
		fill(b, b + i, true);
		for (int j = 0; j < n; j += i) {
			for (int k = 0; k < i; ++k) {
				b[k] &= a[j + k];
			}
		}
		if (count(b, b + i, true) > 0) {
			puts("YES");
			exit(0);
		}
	}
	puts("NO");
	return 0;
}

