#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1024;

void solve(int n, double a[], double b[], double c[], double d[]) {
	for (int i = 1; i < n; ++i) {
		double m = a[i] / b[i - 1];
		b[i] -= m * c[i - 1];
		d[i] -= m * d[i - 1];
	}
	d[n - 1] /= b[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		d[i] = (d[i] - c[i] * d[i + 1]) / b[i];
	}
}

double a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
	int n, m, x, y;

	scanf("%d%d%d%d", &n, &m, &x, &y);
	fill(d, d + m, 0);
	for (int i = n - 1; i >= x; --i) {
		fill(a, a + m, -1);
		fill(b, b + m, 3);
		fill(c, c + m, -1);
		a[0] = c[m - 1] = 0;
		b[0] -= 1;
		b[m - 1] -= 1;
		for (int j = 0; j < m; ++j) {
			d[j] += b[j] + 1;
		}
		solve(m, a, b, c, d);
	}
	printf("%.10lf\n", d[y - 1]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//302008 	Feb 25, 2011 9:53:22 AM 	watashi 	24D - Broken robot 	GNU C++ 	Accepted 	80 ms 	1400 KB 
