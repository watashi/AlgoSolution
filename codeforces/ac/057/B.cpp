#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
	int n, m, q;
	long long ans = 0;

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d", &d[i]);
		for (int j = 0; j < m; ++j) {
			if (a[j] <= d[i] && d[i] <= b[j]) {
				ans += c[j] + (d[i] - a[j]);
			}
		}
	}
	printf("%I64d\n", ans);

	return 0;
}

