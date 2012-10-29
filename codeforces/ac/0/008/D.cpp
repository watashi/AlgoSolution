#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

pair<double, double> gao(double r, double x, double y, double z) {
	double s = hypot(x, y);
	double d = (r * r - z * z) / s;
	double a = atan2(y, x);
	double b = acos(max(-1.0, min(1.0, (s + d) / 2 / r)));
	return make_pair(a - b, a + b);
}

bool between(const pair<double, double>& a, double b) {
	while (b < a.first) {
		b += 2 * PI;
	}
	while (b > a.second) {
		b -= 2 * PI;
	}
	return a.first <= b;
}

bool inter(const pair<double, double>& a, const pair<double, double>& b) {
	return between(a, b.first) || between(a, b.second) || between(b, a.first) || between(b, a.second);
}

int main() {
	double ans, t1, t2, x[3], y[3], z[3], d[3];

	scanf("%lf%lf", &t1, &t2);
	swap(t1, t2);
	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf", &x[i], &y[i]);
	}
	for (int i = 0; i < 3; ++i) {
		d[i] = hypot(x[(i + 1) % 3] - x[i], y[(i + 1) % 3] - y[i]);
	}

	ans = 0;
	if (d[0] + d[1] + d[1] <= d[2] + d[1] + t2) {
		ans = max(ans, d[0] + min(t1, (d[2] + d[1] + t2) - (d[0] + d[1] + d[1])));
	}
	if (d[2] + d[1] <= d[0] + t1) {
		ans = max(ans, d[2] + d[1] + min(t2, (d[0] + t1) - (d[2] + d[1])));
	}

	double l = 0;
	double r = min(d[0] + t1, d[2] + t2);
	for (int i = 0; i < 100; ++i) {
		double m = (l + r) / 2;
		z[0] = m;
		z[1] = d[0] + t1 - m;
		z[2] = d[2] + t2 - m;
		if (d[0] > z[0] + z[1] || d[1] > z[1] + z[2] || d[2] > z[2] + z[0]) {
			r = m;
		} else if (fabs(z[0] - z[1]) >= d[0] || fabs(z[0] - z[2]) >= d[2] || fabs(z[1] - z[2]) >= d[1]) {
			l = m;
		} else {
			bool flag = false;
			pair<double, double> a, b;
			for (int i = 0; i < 3; ++i) {
				a = gao(z[i], x[(i + 1) % 3] - x[i], y[(i + 1) % 3] - y[i], z[(i + 1) % 3]);
				b = gao(z[i], x[(i + 2) % 3] - x[i], y[(i + 2) % 3] - y[i], z[(i + 2) % 3]);
				flag |= inter(a, b);
			}
			if (flag) {
				l = m;
			} else {
				r = m;
			}
		}
	}
	ans = max(ans, (l + r) / 2);
	printf("%.10lf\n", ans);

	return 0;
}

// 判断三个圆是否有公共部分！！

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//444475 	May 10, 2011 7:56:03 PM 	watashi 	8D - Two Friends 	GNU C++ 	Accepted 	30 ms 	1300 KB 
