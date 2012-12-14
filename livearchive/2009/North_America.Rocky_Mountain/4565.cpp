#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 128;

double EPS = 1e-8;
double a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
	int n, m, r;
	double s, t;

	while (scanf("%d%d%d", &n, &m, &r) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &a[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &b[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &c[i]);
		}
		s = accumulate(c, c + n, 0.0);
		copy(c, c + n, d);

		for (int i = 0; i < m; ++i) {
			if (i % r == 0) {
				t = accumulate(d, d + n, 0.0);
				for (int j = 0; j < n; ++j) {
					d[j] = t / s * c[j];
				}
			}
			for (int j = 0; j < n; ++j) {
				scanf("%lf", &t);
				if (d[j] == 0) {
					continue;
				}
				d[j] = d[j] * (1 - b[j] + t) - a[j];
				if (d[j] < EPS) {
					d[j] = 0;
				}
			}
		}

		for (int i = 0; i < n; ++i) {
			printf("%.2lf%c", d[i], (i == n - 1 ? '\n' : ' '));
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714989  	2011-01-04 06:25:05 	Accepted	0.004	Minimum	26909	C++	4565 - Balance

/*
id => 1174238
pid => 4565
pname => Balance
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:43:16
*/
