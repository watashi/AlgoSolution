#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	long long x, y;
	void operator-=(Point p) {
		x -= p.x;
		y -= p.y;
	}
	bool operator==(Point p) {
		return x == p.x && y == p.y;
	}
	double operator*(Point p) {
		return x * p.x + y * p.y;
	}
	double operator%(Point p) {
		return x * p.y - y * p.x;
	}
};

struct Line {
	Point a, b;
} s[3];

bool gao(Point p, Point q) {
	long long a = (p * q), b = (q * q);
	return p % q == 0 && b <= 5 * a && 5 * a <= 4 * b;
}

bool gao(Line m, Line l, Line r) {
	l.b -= l.a;
	r.b -= r.a;
	m.a -= l.a;
	m.b -= r.a;
	return l.a == r.a && l.b % r.b != 0 && l.b * r.b >= 0 && gao(m.a, l.b) && gao(m.b, r.b);
}

int main() {
	int re;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		for (int i = 0; i < 3; ++i) {
			cin >> s[i].a.x >> s[i].a.y >> s[i].b.x >> s[i].b.y;
		}
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j) {
				for (int k = 0; k < 2; ++k) {
					for (int l = 0; l < 3; ++l) {
						if (gao(s[l], s[(l + 1) % 3], s[(l + 2) % 3])) {
							cout << "YES" << endl;
							goto NEXT;
						}
					}
					swap(s[2].a, s[2].b);
				}
				swap(s[1].a, s[1].b);
			}
			swap(s[0].a, s[0].b);
		}
		cout << "NO" << endl;
NEXT:
		continue;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//276028 	Feb 6, 2011 11:11:05 AM 	watashi 	13B - Letter A 	GNU C++ 	Accepted 	420 ms 	1300 KB 
