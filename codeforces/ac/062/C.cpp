#include <cmath>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-6;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double abs() const { return hypot(x, y); }
};

Point operator+(const Point& lhs, const Point& rhs) {
	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

double operator/(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - rhs.x * lhs.y;
}

int signum(double x) {
	return fabs(x) < EPS ? 0 : x > 0 ? 1 : -1;
}

bool sameSide(const Point& a, const Point& b, const Point& c, const Point& d) {
	Point p = b - a;
	return signum(p / (c - a)) == signum(p / (d - a));
}

double intersection(const Point& a, const Point& b, const Point& c, const Point& d) {
	Point p = b - a, q = d - c;
	return ((c - a) / q) / (p / q);
}

Point p[3];
vector<pair<Point, Point> > v;
vector<pair<double, int> > w;

int main() {
	int n;
	double ans = 0.0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 3; ++j) {
			scanf("%lf%lf", &p[j].x, &p[j].y);
		}
		if (signum((p[1] - p[0]) / (p[2] - p[0])) < 0) {
			swap(p[1], p[2]);
		}
		for (int j = 0; j < 3; ++j) {
			v.push_back(make_pair(p[j], p[(j + 1) % 3]));
		}
	}
	
	n = v.size();
	for (int i = 0; i < n; ++i) {
		w.clear();
		w.push_back(make_pair(0, 0));
		w.push_back(make_pair(1, 0));
		for (int j = 0; j < n; j += 3) {
			if (i / 3 == j / 3) {
				continue;
			}
			vector<double> u;
			for (int k = j; k < j + 3; ++k) {
				if (!sameSide(v[i].first, v[i].second, v[k].first, v[k].second)) {
					u.push_back(intersection(v[i].first, v[i].second, v[k].first, v[k].second));
				}
			}
			if (!u.empty()) {
				w.push_back(make_pair(*min_element(u.begin(), u.end()), -1));
				w.push_back(make_pair(*max_element(u.begin(), u.end()), 1));
			}
		}
		sort(w.begin(), w.end());
		
		for (int j = 0, k = 0; j < (int)w.size() - 1; ++j) {
			k += w[j].second;
			if (k >= 0 && 0 <= w[j].first && w[j + 1].first <= 1) {
				ans += (w[j + 1].first - w[j].first) * (v[i].second - v[i].first).abs();
			}
		}
	}
	printf("%.10lf\n", ans);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//433421 	May 5, 2011 9:33:32 PM 	watashi 	62C - Inquisition 	GNU C++ 	Accepted 	30 ms 	1400 KB 
