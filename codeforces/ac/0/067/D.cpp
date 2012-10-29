#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;
int a[MAXN], b[MAXN];

int main() {
	int n, m;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &m);
		a[m] = i;
	}
	for (int i = n; i >= 1; --i) {
		scanf("%d", &m);
		b[i] = a[m];
	}

	m = 1;
	a[0] = b[1];
//	printf("%d ", b[1]);
	for (int i = 2; i <= n; ++i) {
		if (b[i] > a[m - 1]) {
			a[m++] = b[i];
		} else {
			*lower_bound(a, a + m, b[i]) = b[i];
		}
//		printf("%d ", b[i]);
	}
//	puts("");
	printf("%d\n", m);
	
	return 0;
}

