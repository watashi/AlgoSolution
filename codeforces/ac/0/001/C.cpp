#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double length() const { return hypot(x, y); }
	double polar() const { return atan2(y, x); }
	Point normal() const { return Point(y, -x); }
	Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
	Point operator*(const double o) const { return Point(x * o, y * o); }
	double operator*(const Point& o) const { return x * o.y - y * o.x; }
};

Point intersection(const Point& u1, const Point& u2, const Point& v1, const Point& v2) {
	return u1 + (u2 - u1) * (((u1 - v1) * (v1 - v2)) / ((u1 - u2) * (v1 - v2)));
}

double gcd(double a, double b) {
	return fabs(b) < 1e-4 ? a : gcd(b, fmod(a, b));	// EPS should be large enough!
}

int main() {
	Point p[3], o;
	double a[3], r, g, s;

	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	o = intersection(
		(p[0] + p[1]) * .5, (p[0] + p[1]) * .5 + (p[1] - p[0]).normal(),
		(p[0] + p[2]) * .5, (p[0] + p[2]) * .5 + (p[2] - p[0]).normal());
	for (int i = 0; i < 3; ++i) {
		a[i] = (p[i] - o).polar();
	}
	r = (p[0] - o).length();
	g = gcd(2 * M_PI, gcd(fabs(a[1] - a[0]), fabs(a[2] - a[0])));
	s = M_PI * r * r * sin(g) / g;
//	printf("%.0lf\n", 2 * M_PI / g);
	printf("%.9lf\n", s);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218647 	Dec 12, 2010 7:55:58 PM 	watashi 	C - Ancient Berland Circus 	GNU C++ 	Accepted 	30 ms 	1292 KB 

