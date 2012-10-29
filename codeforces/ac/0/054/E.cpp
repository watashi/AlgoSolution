#include <cmath>
#include <limits>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y): x(x), y(y) { }
};

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

double operator*(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

double operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

Point p[1 << 20], q;
double s[1 << 20];

double triangle(const Point& lhs, const Point& rhs) {
	return fabs((lhs * rhs) * (lhs % rhs) / (rhs * rhs));
}

double area(int i, int j) {
	return fabs(s[j] - s[i] + p[i] % p[j]);
}

int main() {
	int n;
	double pre, tmp, ans = numeric_limits<double>::max();

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	copy(p, p + n, p + n);
	copy(p, p + n, p + n + n);
	s[0] = 0;
	for (int i = 1; i < n + n + n; ++i) {
		s[i] = p[i] % p[i - 1];
	}
	partial_sum(s, s + n + n + n, s);

	for (int i = n, j = n, k = 1; i < n + n; ++i) {
		q = p[i + 1] - p[i];
		pre = (p[j] - p[i + 1]) * q;
		while (true) {
			tmp = (p[j + 1] - p[i + 1]) * q;
			if (pre >= 0 && pre >= tmp) {
				break;
			}
			pre = max(pre, tmp);
			++j;
		}
		ans = min(ans, triangle(p[j] - p[i + 1], q) - area(i + 1, j));

		q = p[i] - p[i + 1];
		pre = (p[k] - p[i]) * q;
		while (true) {
			tmp = (p[k + 1] - p[i]) * q;
			if (pre >= 0 && pre >= tmp) {
				break;
			}
			pre = max(pre, tmp);
			++k;
		}
		ans = min(ans, triangle(p[k] - p[i], q) - area(k, i));
	}
	printf("%.10lf\n", ans / 2);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//251920 	Jan 14, 2011 5:12:37 PM 	watashi 	54E - Vacuum Сleaner 	GNU C++ 	Accepted 	110 ms 	25900 KB 

