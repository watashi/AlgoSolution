#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 5050;
double x[MAXN], y[MAXN], z[MAXN], r[MAXN];

inline double sqr(double x) {
	return x * x;
}

int main() {
	int n;
	double ans;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
		r[i] = sqrt(sqr(x[i] - x[0]) + sqr(y[i] - y[0]) + sqr(z[i] - z[0]));
	}
	ans = 1e100;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < i; ++j) {
			ans = min(ans, r[i] + r[j] + sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j])));
		}
	}
	printf("%.10lf\n", ans / 2);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//404494 	Apr 21, 2011 2:23:24 PM 	watashi 	44D - Hyperdrive 	GNU C++ 	Accepted 	380 ms 	1500 KB 
