#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	Point vn() const { return Point(y, -x); }
} p[3], q[4];

Point operator+(const Point& lhs, const Point& rhs) {
	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

Point operator*(const double& lhs, const Point& rhs) {
	return Point(lhs * rhs.x, lhs * rhs.y);
}

double operator/(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

bool gao() {
	q[0] = 0.5 * (p[0] + p[1]);
	q[1] = 0.5 * (p[0] + p[2]);
	q[2] = (p[1] - p[0]).vn();
	q[3] = (p[2] - p[0]).vn();
	double a[2][3] = {
		{q[2].x, q[3].x, 2 * p[0].x - q[0].x - q[1].x},
		{q[2].y, q[3].y, 2 * p[0].y - q[0].y - q[1].y}};
	double d = a[0][0] * a[1][1] - a[1][0] * a[0][1];
	double u = (a[0][2] * a[1][1] - a[1][2] * a[0][1]) / d;
	double v = (a[0][0] * a[1][2] - a[1][0] * a[0][2]) / d;
	q[0] = q[0] + u * q[2];
	q[1] = q[1] + v * q[3];
	q[2] = 2 * p[2] - q[1];
	q[3] = 2 * p[1] - q[0];
	for (int i = 0; i < 4; ++i) {
		if ((q[i] - q[(i + 1) % 4]) / (q[(i + 2) % 4] - q[(i + 1) % 4]) < EPS) {
			return false;
		}
	}
	return true;
}

int main() {
	int re;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 0; i < 3; ++i) {
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		if ((p[1] - p[0]) / (p[2] - p[0]) < -EPS) {
			swap(p[1], p[2]);
		}
		if ((p[1] - p[0]) / (p[2] - p[0]) > EPS) {
			for (int i = 0; i < 3; ++i) {
				if (gao()) {
					puts("YES");
					for (int i = 0; i < 4; ++i) {
						printf("%.10lf %.10lf ", q[i].x, q[i].y);
					}
					goto NEXT;
				}
				rotate(p, p + 1, p + 3);
			}
		}
		puts("NO");
NEXT:
		puts("");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//414482 	Apr 29, 2011 3:42:52 PM 	watashi 	23D - Tetragon 	GNU C++ 	Accepted 	670 ms 	1300 KB
