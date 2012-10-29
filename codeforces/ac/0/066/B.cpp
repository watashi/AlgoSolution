#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10000;
const int INF = 1000000007;
int a[MAXN];

int main() {
	int n, l, r, m;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	a[0] = a[n + 1] = INF;
	m = 0;
	for (int i = 1; i <= n; ++i) {
		for (l = i - 1; a[l] <= a[l + 1]; --l) {
		}
		for (r = i + 1; a[r] <= a[r - 1]; ++r) {
		}
		m = max(m, r - l);
	}
	printf("%d\n", m - 1);

	return 0;
}

