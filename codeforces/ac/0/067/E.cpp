#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 4096;

struct Point {
	long long x, y;
	Point() { }
	Point(long long x, long long y) : x(x), y(y) { }
} p[MAXN], pa, pb;

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

long long operator*(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

long long operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

void intersection(const Point& u1, const Point& u2, const Point& v1, const Point& v2,
		long long& num, long long& den) {
	static long long gcd;
	num = (u1 - v1) * (v1 - v2);
	den = (u1 - u2) * (v1 - v2);
	if (den < 0) {
		num = -num;
		den = -den;
	}
	gcd = ::gcd(num >= 0 ? num : -num, den);
	num /= gcd;
	den /= gcd;
}

long long floor(long long a, long long b);
long long ceil(long long a, long long b);

long long floor(long long a, long long b) {
	return a >= 0 ? a / b : -ceil(-a, b);
}

long long ceil(long long a, long long b) {
	return a >= 0 ? (a + b - 1) / b : -floor(-a, b);
}

int main() {
	int n;
	long long num, den;
	long long left, right, cross;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
	}
	// p[n] = p[0];
	pa = p[0];
	pb = p[1];
	if (pa.x > pb.x) {
		swap(pa, pb);
	}
	left = pa.x;
	right = pb.x;

	for (int i = 2; i < n - 1; ++i) {
		cross = (p[i + 1] - p[i]) * (pb - pa);
		if (cross != 0) {
			intersection(pa, pb, p[i], p[i + 1], num, den);
	//		cout << (cross > 0 ? "[+] " : "[-] ") << num << "/" << den << endl;
			if (cross > 0) {
				right = min(right, pa.x + floor((pb.x - pa.x) * num, den));
			} else if (cross < 0) {
				left = max(left, pa.x + ceil((pb.x - pa.x) * num, den));
			}
	/* WHAT A F*********************KING BUG
		} else if ((p[i + 1] - p[i]) % (pb - pa) > 0) {
			cout << 0 << endl;
			return 0;
		}
	*/ // 这个BUG值600块钱！！
		} else if ((p[i + 1] - p[i]) % (p[1] - p[0]) > 0) {
			cout << 0 << endl;
			return 0;
		}
	}
	cout << max(right - left + 1, 0LL) << endl;
	return 0;
}

