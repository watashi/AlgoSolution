#include <cstdio>
#include <algorithm>

int main() {
	int n, m, h;
	int s, t, x;

	scanf("%d%d%d", &n, &m, &h);
	s = t = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &x);
		s += x;
		if (i != h) {
			t += x;
		}
	}
	--n;
	--s;

//	printf("%d %d\n", s, t);
	if (s < n) {
		puts("-1");
	} else if (t < n) {
		puts("1");
	} else {
		double ans = 1.0;
		for (int i = 0; i < n; ++i) {
			ans /= s - i;
			ans *= t - i;
		}
		ans = 1.0 - ans;
		printf("%.16lf\n", ans);
	}

	return 0;
}

