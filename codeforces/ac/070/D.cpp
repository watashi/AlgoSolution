#include <map>
#include <cmath>
#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
};

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

double operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - rhs.x * lhs.y;
}

typedef map<double, Point> Map;
typedef Map::iterator Itr;

Itr id(Map& mp, Itr it) {
	if (it == mp.end()) {
		it = mp.begin();
	}
	return it;
}

Itr prev(Map& mp, Itr it) {
	if (it == mp.begin()) {
		it = mp.end();
	}
	--it;
	return it;
}

Itr succ(Map& mp, Itr it) {
	++it;
	if (it == mp.end()) {
		it = mp.begin();
	}
	return it;
}

int main() {
	int n, t;
	double a;
	Point p[3], q;
	Map mp;
	Itr it, jt, kt;

	scanf("%d", &n);
	q.x = q.y = 0;
	for (int i = 0; i < 3; ++i) {
		scanf("%d%lf%lf", &t, &p[i].x, &p[i].y);
		q.x += p[i].x;
		q.y += p[i].y;
	}
	q.x = q.x / 3 + 0.01;
	q.y = q.y / 3 + 0.01;
	for (int i = 0; i < 3; ++i) {
		p[i].x -= q.x;
		p[i].y -= q.y;
		mp[atan2(p[i].y, p[i].x)] = p[i];
	}

	for (int i = 3; i < n; ++i) {
		scanf("%d%lf%lf", &t, &p[0].x, &p[0].y);
		p[0].x -= q.x;
		p[0].y -= q.y;
		a = atan2(p[0].y, p[0].x);
		it = id(mp, mp.lower_bound(a));
		jt = prev(mp, it);
//		printf("(%lf, %lf) -- (%lf, %lf)\n", jt->second.x, jt->second.y, it->second.x, it->second.y);

//		printf("@%d:\n", i);
//		for (Itr j = mp.begin(); j != mp.end(); ++j) {
//			printf("%lf (%lf, %lf)\n", j->first, j->second.x, j->second.y);
//		}
		if (t == 2) {
			puts((jt->second - p[0]) % (it->second - p[0]) > -EPS ? "YES" : "NO");
		} else if ((it->second - p[0]) % (jt->second - p[0]) > EPS) {
			kt = succ(mp, it);
			while ((kt->second - p[0]) % (it->second - p[0]) > -EPS) {
				mp.erase(it);
				it = kt;
				kt = succ(mp, it);
			}
			kt = prev(mp, jt);
			while ((jt->second - p[0]) % (kt->second - p[0]) > -EPS) {
				mp.erase(jt);
				jt = kt;
				kt = prev(mp, jt);
			}
			mp[a] = p[0];
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//443401 	May 9, 2011 6:19:35 AM 	watashi 	70D - Professors task 	GNU C++ 	Accepted 	300 ms 	1600 KB 
