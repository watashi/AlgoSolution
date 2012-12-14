#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y): x(x), y(y) { }
	double abs() const { return hypot(x, y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
	bool operator==(const Point& o) const { return (*this - o).abs() < 1e-8; }
};

const double SQRT3 = sqrt(3);
const Point dir[3] = {Point(0, SQRT3), Point(1.5, SQRT3 / 2), Point(-1.5, SQRT3 / 2)};

Point toc(const Point& p) {
	int xx = (int)(p.x / dir[1].x);
	int yy = (int)(p.y / dir[1].y);
	Point q, r = Point(0, 0);
	for (int i = xx - 1; i <= xx + 1; ++i) {
		for (int j = yy - 2; j <= yy + 2; ++j) {
			if ((i + j) % 2 == 0) {
				q = Point(dir[1].x * i, dir[1].y * j);
				if ((p - q).abs() < (p - r).abs()) {
					r = q;
				}
			}
		}
	}
	return r;
}

double gao(const Point& c, const Point& a, const Point& b) {
	double d = a.x * b.y - a.y * b.x;
	return (fabs(c.x * b.y - c.y * b.x) + fabs(a.x * c.y - a.y * c.x)) / fabs(d);
}

int main() {
	double d, ans;
	Point a, b, s, t;

	while (scanf("%lf%lf%lf%lf%lf", &d, &a.x, &a.y, &b.x, &b.y) != EOF && d > 0) {
		a.x /= d;
		a.y /= d;
		b.x /= d;
		b.y /= d;
		ans = 0.0;
		s = toc(a);
		ans += (a - s).abs();
		t = toc(b);
		ans += (b - t).abs();

		if (s == t) {
			ans = (a - b).abs();
		}
		ans += SQRT3 * min(gao(t - s, dir[0], dir[1]),
			min(gao(t - s, dir[1], dir[2]), gao(t - s, dir[2], dir[0])));
		printf("%.3f\n", ans * d);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805961 	2084 	Problem Bee 	Accepted 	C++ 	0.108 	2011-05-23 16:05:44
/*
id => 1174125
pid => 2084
pname => Problem Bee
status => Accepted
lang => C++
time => 0.102
date => 2012-12-14 17:27:00
*/
