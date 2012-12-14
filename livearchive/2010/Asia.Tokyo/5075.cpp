#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1024;
const double EPS = 1e-8;

struct Point {
	double x, y;

	Point() { }

	Point(double x, double y): x(x), y(y) { }
} p[MAXN], q[MAXN];

void gao(double x, const Point& a, const Point& b, vector<double>& v) {
	if (a.x > b.x) {
		gao(x, b, a, v);
		return;
	}
	if (fabs(a.x - x) < EPS) {
		v.push_back(a.y);
	}
	if (fabs(b.x - x) < EPS) {
		v.push_back(b.y);
	}
	if (a.x < x - EPS && x + EPS < b.x) {
		v.push_back(a.y + (b.y - a.y) / (b.x - a.x) * (x - a.x));
	}
}

double vol(double x1, double x2, double y1, double y2) {
	x2 -= x1;
	y2 -= y1;
	return x2 * y2 / 3 + (x1 * y2 + y1 * x2) / 2 + x1 * y1;
}

int main() {
	int m, n;
	double ans, dy, dz, ty, tz;
	double pxmin, pxmax, qxmin, qxmax;
	vector<double> x, y, z;

	while (scanf("%d%d", &m, &n) != EOF && n > 0 && m > 0) {
		x.clear();
		pxmin = 1e100;
		pxmax = -1e100;
		for (int i = 0; i < m; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
			pxmin = min(pxmin, p[i].x);
			pxmax = max(pxmax, p[i].x);
			x.push_back(p[i].x);
		}
		p[m] = p[0];
		qxmin = 1e100;
		qxmax = -1e100;
		for (int i = 0; i < n; ++i) {
			scanf("%lf%lf", &q[i].x, &q[i].y);
			qxmin = min(qxmin, q[i].x);
			qxmax = max(qxmax, q[i].x);
			x.push_back(q[i].x);
		}
		q[n] = q[0];
		x.erase(remove_if(x.begin(), x.end(), bind2nd(less<double>(), max(pxmin, qxmin))), x.end());
		x.erase(remove_if(x.begin(), x.end(), bind2nd(greater<double>(), min(pxmax, qxmax))), x.end());
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());

		ty = tz = 0;
		ans = 0;
		for (vector<double>::const_iterator it = x.begin(); it != x.end(); ++it) {
			y.clear();
			z.clear();
			for (int i = 0; i < m; ++i) {
				gao(*it, p[i], p[i + 1], y);
			}
			for (int i = 0; i < n; ++i) {
				gao(*it, q[i], q[i + 1], z);
			}
			sort(y.begin(), y.end());
			sort(z.begin(), z.end());
			dy = y.back() - y.front();
			dz = z.back() - z.front();
			if (it != x.begin()) {
				ans += vol(ty, dy, tz, dz) * (*it - *(it - 1));
			}
			ty = dy;
			tz = dz;
		}
		printf("%.10lf\n", ans);
	}
	
	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//885903 	5075 	Intersection of Two Prisms 	Accepted 	C++ 	0.008 	2011-09-20 13:11:26
/*
id => 1174080
pid => 5075
pname => Intersection of Two Prisms
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:19:41
*/
