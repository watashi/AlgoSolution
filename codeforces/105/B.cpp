#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10;

int n, m, a, x[MAXN], y[MAXN], b[1 << MAXN];
double p[MAXN], q[MAXN], r[1 << MAXN], s[1 << MAXN];

double gao(int i, int j) {
	double ret = 0;
	if (i == n && j == 0) {
		r[0] = s[0] = 1;
		for (int m = 1; m < (1 << n); ++m) {
			int t = __builtin_ctz(m);
			r[m] = r[m ^ (1 << t)] * p[t];
			s[m] = s[m ^ (1 << t)] * q[t];
		}
		for (int m = 0; m < (1 << n); ++m) {
			double rs = r[((1 << n) - 1) ^ m] * s[m];
			if (__builtin_popcount(m) * 2 < n) {
				ret += rs;
			} else {
				ret += rs * a / (a + b[m]);
			}
		}
	} else if (i < n) {
		for (int k = 0; k <= y[i] && k <= j; ++k) {
			q[i] = (y[i] - k) / 10.0;
			p[i] = 1.0 - q[i];
			ret = max(ret, gao(i + 1, j - k));
		}
	}
	return ret;
}

int main() {
	cin >> n >> m >> a;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		y[i] = 10 - y[i] / 10;
	}
	b[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		int j = __builtin_ctz(i);
		b[i] = b[i ^ (1 << j)] + x[j];
	}
	p[0] = 1;
	printf("%.10lf\n", gao(0, min(m, accumulate(y, y + n, 0))));

	return 0;
}

