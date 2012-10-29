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

double a[MAXN];
double v[MAXN][MAXN], w[MAXN][MAXN];
int s[MAXN][MAXN], t[MAXN][MAXN];

int main() {
	int n, m, cnt, ans;

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &r[i].x, &r[i].y);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%lf%lf", &b[i].x, &b[i].y);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[j] = (b[j] - r[i]).arg();
		}
		sort(a, a + m);
		for (int j = 0; j < n; ++j) {
			if (j == i) {
				continue;
			}
			v[i][j] = (r[j] - r[i]).arg();
			s[i][j] = upper_bound(a, a + m, v[i][j]) - a;
			w[i][j] = (v[i][j] < 0 ? v[i][j] + M_PI : v[i][j] - M_PI);
			t[i][j] = upper_bound(a, a + m, w[i][j]) - a;
		}
	}

	ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = i + 1; k < n; ++k) {
				if (j == k || (r[j] - r[i]) % (r[k] - r[j]) >= 0) {
					continue;
				}
				cnt = 0;
				cnt += t[i][k] - s[i][j] + (w[i][k] > v[i][j] ? 0 : m);
				cnt += t[j][i] - s[j][k] + (w[j][i] > v[j][k] ? 0 : m);
				cnt += t[k][j] - s[k][i] + (w[k][j] > v[k][i] ? 0 : m);
			//	printf("(%d,%d,%d) = %d\n", i, j, k, cnt);
				if (cnt == m) {
					++ans;
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//276051 	Feb 6, 2011 12:20:42 PM 	watashi 	13D - Triangles 	GNU C++ 	Accepted 	1560 ms 	7500 KB
