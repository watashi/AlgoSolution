#include <iostream>
#include <algorithm>

using namespace std;
using namespace rel_ops;

struct Point {
	long long x, y;

	Point() { }

	Point(long long x, long long y): x(x), y(y) { }
	
	Point rot() const { return Point(y, -x); }

	bool operator==(const Point& o) const { return x == o.x && y == o.y; }
	
	Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }

	long long operator*(const Point& o) const { return x * o.x + y * o.y; }
};

/*
bool issqr(long long x) {
	long long l = 0, r = 1000000007;
	
	while (l < r) {
		long long m = (l + r) / 2;
		if (m * m < x) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	
	return r * r == x;
}
*/

bool gao(const Point& a, const Point& b) {
	long long u = a * b, v = b * b;
	return u % v == 0;// && issqr(llabs(u / v));
}

int main() {
	const Point O(0, 0);
	Point a, b, c, d, x, y;

	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;
	x = c;
	y = x.rot();
	for (int i = 0; i < 4; ++i) {
		a = a.rot();
		d = b - a;
		if (d == O || (x != O && y != O && gao(d, x) && gao(d, y))) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}

