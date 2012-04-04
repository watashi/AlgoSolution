#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const double EPS = 1e-8;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y): x(x), y(y) { }
	Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
};

double sq(double x) {
	return x * x;
}

double gao(double a, double b, double c, double d, double v) {
	if (d + c < b / v - EPS) {
		return -1;
	}
	double e = (a * a - b * b) / c;
	double s = -(c + e) / 2;
	double t = (c - e) / 2;
	double h = sqrt(max(0.0, a * a - s * s));
	double l = 0.0, r = 1.0;
	for (int i = 0; i < 100; ++i) {
		double m = (l + r) / 2;
		if (d + m * c < hypot(h, s + (t - s) * m) / v) {
			l = m;
		} else {
			r = m;
		}
	}
	return (l + r) / 2;
}

double x[MAXN], y[MAXN], z[MAXN], r[MAXN], d[MAXN];

int main() {
	int n;
	double vs, vp, xx, yy, zz, tmp;

	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	}
	scanf("%lf%lf", &vp, &vs);
	scanf("%lf%lf%lf", &xx, &yy, &zz);
	for (int i = 0; i <= n; ++i) {
		r[i] = sqrt(sq(x[i] - xx) + sq(y[i] - yy) + sq(z[i] - zz));
		if (i > 0) {
			d[i] = d[i - 1] + sqrt(sq(x[i] - x[i - 1]) + sq(y[i] - y[i - 1]) + sq(z[i] - z[i - 1]));
		} else {
			d[i] = 0;
		}
	}

	vp /= vs;
	for (int i = 0; i < n; ++i) {
		tmp = gao(r[i], r[i + 1], d[i + 1] - d[i], d[i], vp);
		if (tmp != -1) {
			puts("YES");
			printf("%.10lf\n", (d[i] + tmp * (d[i + 1] - d[i])) / vs);
			printf("%.10lf %.10lf %.10lf\n",
				x[i] + tmp * (x[i + 1] - x[i]),
				y[i] + tmp * (y[i + 1] - y[i]),
				z[i] + tmp * (z[i + 1] - z[i]));
			return 0;
		}
	}
	puts("NO");

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443953 	May 9, 2011 9:42:09 PM 	watashi 	65C - Harry Potter and the Golden Snitch 	GNU C++ 	Accepted 	50 ms 	1700 KB 
