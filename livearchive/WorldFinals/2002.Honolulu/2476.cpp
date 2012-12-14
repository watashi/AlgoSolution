#include <cmath>
#include <cstdio>

const int MAXN = 100;
const double EPS = 1e-8;
const double INF = 1000000 + EPS;

double hypot_(double x, double y) {
	return sqrt(x * x + y * y);
}

int main() {
	int ri = 0, n, c;
	bool mark[MAXN];
	double m, z, t, x[MAXN], y[MAXN], d[MAXN];

	while (scanf("%d%lf", &n, &m) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &x[i], &y[i]);
			mark[i] = false;
			d[i] = INF;
		}
		d[n - 1] = 0;

		for (int i = 0; i < n; ++i) {
			int k = -1;
			for (int j = 0; j < n; ++j) {
				if (!mark[j] && (k == -1 || d[j] < d[k])) {
					k = j;
				}
			}
			mark[k] = true;
			for (int j = 0; j < n; ++j) {
				if (mark[j]) {
					continue;
				}
				z = hypot_(x[j] - x[k], y[j] - y[k]);
				if (m - z - z >= d[k] - EPS) {
					t = d[k] + z;
				} else if (m >= 3 * z - EPS) {
					c = (int)((d[k] - z) / (m - 3 * z) - EPS);
					t = d[k] - c * (m - 3 * z) + z;
					t += c * (m - z);
				} else {
					t = INF;
				}
				if (t < d[j]) {
					d[j] = t;
				}
			}
		}

		printf("Trial %d: ", ++ri);
		if (d[0] == INF) {
			puts("Impossible");
		} else {
			printf("%.0lf units of food\n", ceil(d[0] - EPS));
		}
		puts("");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722960  	2011-01-20 15:09:30 	Accepted	0.033	Minimum	26909	C++	2476 - Crossing the Desert
/*
id => 1174104
pid => 2476
pname => Crossing the Desert
status => Accepted
lang => C++
time => 0.025
date => 2012-12-14 17:22:43
*/
