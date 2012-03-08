#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
double a[MAXN];

int main() {
	int n, k;
	double carry, rate, l, r, m;

	scanf("%d%d", &n, &k);
	rate = 0.01 * (100 - k);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &a[i]);
	}
	
	l = 0;
	r = *max_element(a, a + n);
	for (int i = 0; i < 100; ++i) {
		m = (l + r) / 2;
		carry = 0;
		for (int j = 0; j < n; ++j) {
			if (a[j] > m) {
				carry += (a[j] - m) * rate;
			} else if (a[j] < m) {
				carry -= m - a[j];
			}
		}
		if (carry >= 0) {
			l = m;
		} else {
			r = m;
		}
	}
	printf("%.10lf\n", (l + r) / 2);

	return 0;
}

