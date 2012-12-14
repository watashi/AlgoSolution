#include <cstdio>
#include <algorithm>

using namespace std;

struct Point {
	long long x, y;
	Point() { }
	Point(long long x, long long y) : x(x), y(y) { }
};

long long llabs_(long long x) {
	return x > 0 ? x : -x;
}

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

// p[n] = p[0];
long long gridOnedge(int n, const Point p[]) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += gcd(llabs_(p[i].x - p[i + 1].x), llabs_(p[i].y - p[i + 1].y));
	}
	return ret;
}

// p[n] = p[0]; p[n + 1] = p[1];
long long gridInside_(int n, const Point p[]) {
	long long ret = 0;
	for (int i = 0; i < n; ++i) {
		ret += p[i + 1].y * (p[i].x - p[i + 2].x);
	}
	return llabs_(ret);
}

Point p[1024], q[1024];

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

long long operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

int main() {
	int ri = 0, n, m;
	long long g, lv, a, b, s;

	while (scanf("%d%lld", &n, &lv) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			scanf("%lld%lld", &p[i].x, &p[i].y);
		}
		q[0] = p[0];
		q[1] = p[1];
		m = 2;
		for (int i = 2; i < n; ++i) {
			if ((p[i] - q[m - 2]) % (q[m - 1] - q[m - 2]) == 0) {
				q[m - 1] = p[i];
			} else {
				q[m++] = p[i];
			}
		}
		while ((q[m - 1] - q[0]) % (q[1] - q[0]) == 0) {
			q[0] = q[--m];
		}
		while ((q[m - 1] - q[0]) % (q[m - 1] - q[m - 2]) == 0) {
			--m;
		}
		
		g = 0;
		p[0] = q[0];
		for (int i = 0; i < m; ++i) {
			q[i] = q[i] - p[0];
			g = gcd(g, q[i].x);
			g = gcd(g, q[i].y);
		}
		for (int i = 0; i < m; ++i) {
			q[i].x /= g;
			q[i].y /= g;
//			printf("(%lld, %lld)\n", q[i].x, q[i].y);
		}
		q[m] = q[0];
		q[m + 1] = q[1];
		a = gridInside_(m, q);
		b = gridOnedge(m, q);
		// (a*x^2 - b*x) / 2 + 1
		s = 0;
		for (int i = 1; i <= lv; ++i) {
			s += (a * i - b) * i / 2 + 1;
		}
		//	s = lv * (lv + 1) * (2 * lv + 1) / 6 * a - lv * (lv + 1) / 2 * b;
		printf("Case %d: %lld\n", ++ri, s);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727330  	2011-01-29 09:21:43 	Accepted	0.244	432	26909	C++	2395 - Jacquard Circuits

/*
id => 1174089
pid => 2395
pname => Jacquard Circuits
status => Accepted
lang => C++
time => 0.036
date => 2012-12-14 17:21:00
*/
