#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	double x, y;
	
	Point() {
	}
	
	Point(double x, double y) : x(x), y(y) {
	}

	double abs() const {
		return hypot(x, y);
	}

	Point operator*(double o) const {
		return Point(x * o, y * o);
	}

	Point operator+(const Point& o) const {
		return Point(x + o.x, y + o.y);
	}
	
	Point operator-(const Point& o) const {
		return Point(x - o.x, y - o.y);
	}
};

const double EPS = 1e-8;

// x * y = 0.5
// ax + by = 0.5
bool gao(double a, double b, double& x, double& y) {
	double d = 1 - 8 * a * b;
	if (d < -EPS) {
		return false;
	}
	d = sqrt(max(0.0, d));
	x = (1 - d) / (4 * a);
	if (-EPS < x && x < 1 + EPS) {
		y = 0.5 / x;
		if (-EPS < y && y < 1 + EPS) {
			return true;
		}
	}
	x = (1 + d) / (4 * a);
	if (-EPS < x && x < 1 + EPS) {
		y = 0.5 / x;
		if (-EPS < y && y < 1 + EPS) {
			return true;
		}
	}
	return false;
}

double f(double x) {
	return fabs(x) < EPS ? 0.0 : x;
}

int main() {
	int re, rid;
	double perimeter, x, y, z;
	Point p[4], a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &rid);
		for (int i = 0; i < 3; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		p[3] = p[0];
		perimeter = 0;
		for (int i = 0; i < 3; ++i) {
			perimeter += (p[i + 1] - p[i]).abs();
		}

		for (int i = 0; i < 3; ++i) {
			rotate(p, p + 1, p + 3);
			if (!gao((p[1] - p[0]).abs() / perimeter, (p[2] - p[0]).abs() / perimeter, x, y)) {
				continue;
			}
			a = p[0] + (p[1] - p[0]) * x;
			b = p[0] + (p[2] - p[0]) * y;
			x = b.x - a.x;
			y = b.y - a.y;
			z = hypot(x, y);
			x /= z;
			y /= z;
			if (y < 0) {
				x = -x;
				y = -y;
			}
			z = a.x * y - a.y * x;
			printf("%d %.5lf %.5lf %.5lf\n", rid, f(y), f(-x), f(z));
			break;
		}
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//881220 	4881 	Cutting The Cake 	Accepted 	C++ 	0.056 	2011-09-13 13:42:41
/*
id => 1174166
pid => 4881
pname => Cutting The Cake
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:32:41
*/
