#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 512;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double arg() const { return atan2(y, x); }
} r[MAXN], b[MAXN];

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

double operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

int c[MAXN][MAXN];

int main() {
	int n, m, ans;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &r[i].x, &r[i].y);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%lf%lf", &b[i].x, &b[i].y);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (r[i].x >= r[j].x) {
				continue;
			}
			for (int k = 0; k < m; ++k) {
				if (r[i].x <= b[k].x && b[k].x < r[j].x && (r[j] - r[i]) % (b[k] - r[i]) > 0) {
					++c[i][j];
				}
			}
			c[j][i] = -c[i][j];
		}
	}

	ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				if (c[i][j] + c[j][k] + c[k][i] == 0) {
					++ans;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//276058 	Feb 6, 2011 12:37:59 PM 	watashi 	13D - Triangles 	GNU C++ 	Accepted 	630 ms 	2300 KB 
