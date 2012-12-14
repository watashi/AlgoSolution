#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y): x(x), y(y) { }
	double abs() const { return hypot(x, y); }
	Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
	Point operator*(double o) const { return Point(x * o, y * o); }
	Point scale(double o) const { return *this * (o / abs()); }
};

const double EPS = 1e-8;
const double SQRT2 = sqrt(2.0);
const double SQRT3 = sqrt(3.0);
const double PI = acos(-1.0);
const Point p[] = {
	Point(SQRT3, -1),
	Point(SQRT3, 1),
	Point(0, 2),
	Point(-SQRT3, 1),
	Point(-SQRT3, -1),
	Point(0, -2),
	Point(SQRT3, -1),
	Point(SQRT3, 1),
};

Point gao(int a, int b, int c) {
	if (b < 0) {
		Point t = gao(a, -b, c);
		return Point(2 * SQRT3 - t.x, t.y);
	} else if (c == 0) {
		int l = 0;
		for (int i = 0; i <= 3; ++i) {
			if (l <= a && a < l + 90) {
				double ra = (a - l) * PI / 180;
				double rb = (90 - b) * PI / 180;
				double d1 = SQRT2 / sin(0.75 * PI - ra) * sin(ra);
				double d2 = SQRT2 / sin(0.75 * PI - ra) * sin(0.25 * PI);
				double rc = atan(d2 / SQRT2);
				double d3 = SQRT2 / sin(PI - rb - rc) * sin(rb);
				return (p[i] + (p[i + 1] - p[i]).scale(d1)).scale(d3);
			}
			l = (l + 90) % 360;
		}
	} else {
		int l = 0;
		for (int i = 6; i >= 3; --i) {
			if (l <= a && a < l + 90) {
				double ra = (a - l) * PI / 180;
				double rb = (90 - b) * PI / 180;
				double d1 = SQRT2 / sin(0.75 * PI - ra) * sin(ra);
				double d2 = SQRT2 / sin(0.75 * PI - ra) * sin(0.25 * PI);
				double rc = atan(d2 / SQRT2);
				double d3 = SQRT2 / sin(PI - rb - rc) * sin(rb);
				return (p[i] + (p[i + 1] - p[i]).scale(d1)).scale(d3);
			}
			l = (l + 270) % 360;
		}
	}
}

int main() {
	int ri = 0, a1, b1, a2, b2;
	double ans;

	while (scanf("%d%d%d%d", &a1, &b1, &a2, &b2) != EOF && a1 >= 0) {
		b1 = 90 - b1;
		b2 = 90 - b2;
		ans = 1e99;
		for (int k = 0; k < 4; ++k) {
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 2; ++j) {
					Point p1 = gao(a1, b1, i);
					Point p2 = gao(a2, b2, j);
					if ((i != j) ^ ((p1.x - SQRT3) * (p2.x - SQRT3) > -EPS)) {
						ans = min(ans, (p1 - p2).abs());
					}
				}
			}
			a1 = (a1 + 90) % 360;
			a2 = (a2 + 90) % 360;
		}
		printf("Case %d: %.3lf\n", ++ri, ans * 5.0);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//800097 	4447 	The Return of Carl 	Accepted 	C++ 	0.008 	2011-05-17 13:05:51
/*
id => 1174042
pid => 4447
pname => The Return of Carl
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:14:20
*/
