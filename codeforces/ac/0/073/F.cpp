#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const double EPS = 1e-6;
const double PI = atan2(0.0, -1.0);

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double abs() const { return hypot(x, y); }
	double arg() const { return atan2(y, x); }
};

Point operator+(const Point& lhs, const Point& rhs) {
	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

Point operator*(const double& lhs, const Point& rhs) {
	return Point(lhs * rhs.x, lhs * rhs.y);
}

double operator*(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

double operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - rhs.x * lhs.y;
}

double off(double a, double b) {
	a -= b;
	while (a < -PI) {
		a += 2 * PI;
	}
	while (a >= PI) {
		a -= 2 * PI;
	}
	return a;
}

double dis(double a, double b) {
	return fabs(off(a, b));
}

double gao(const Point& a, const Point& b, Point p, double q, double w) {
	double d = (b - a).abs();
	double h = fabs((p - a) % (b - a)) / d;
	if ((p - a) % (b - a) > 0) {
		p = p + 2 * h / d * Point(a.y - b.y, b.x - a.x);
		q = (b - a).arg() * 2 - q;
	}
	double q0 = (b - a).arg() - PI / 2;
	double qa = off((a - p).arg(), q0);
	double qb = off((b - p).arg(), q0);
	double qq = off(q, q0);
	
//	printf("%lf %lf %lf h=%lf (%lf, %lf)\n", qq, qa, qb, h, h * w, d / (dis(qq, qb) / w));

	double l = d / (dis(qq, qb) / w), r = 1e8;
	
	while (r - l > EPS) {
		double m = (l + r) / 2;
		double qc = h * w >= m ? qb : min(qb, max(qa, -acos(sqrt(h * w / m))));
//		printf("%lf %lf %lf %lf\n", m, qc, dis(qq, qc) / w, (tan(qc) - tan(qa)) * h / m);
		if (dis(qq, qc) / w <= (tan(qc) - tan(qa)) * h / m) {
			l = m;
		} else {
			r = m;
		}
	}
	return (l + r) / 2;
}

int main() {
	int n, m;
	Point a, b, p;
	double q, w;
	vector<double> v;

	scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf%lf%lf", &p.x, &p.y, &q, &w);
		v.push_back(gao(a, b, p, q, w));
	}

	v.push_back(0);
	sort(v.begin(), v.end());
	scanf("%d", &m);
	printf("%.10lf\n", v[n - m]);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443388 	May 9, 2011 5:34:37 AM 	watashi 	73F - Plane of Tanks 	GNU C++ 	Accepted 	270 ms 	1600 KB 
