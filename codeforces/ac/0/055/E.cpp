#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
	long long x, y;
	Point() { }
	Point(long long x, long long y) : x(x), y(y) { }
};

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

long long operator*(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - lhs.y * rhs.x;
}

long long s[1 << 20];
Point p[1 << 20], q;

int main() {
	int n, re;
	long long l, r, ans;

	for (int i = 2; i < (1 << 20); ++i) {
		s[i] += s[i - 1] + i - 1;
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x >> p[i].y;
		p[n + i] = p[i];
	}
	cin >> re;
	for (int i = 0; i < re; ++i) {
		cin >> q.x >> q.y;
		for (int j = 0; j < n; ++j) {
			if ((p[j] - q) * (p[j + 1] - q) >= 0) {
				cout << 0 << endl;
				goto NEXT;
			}
		}
		
		ans = 0;
		for (int j = 0, k = 0; j < n; ++j) {
			while ((p[j] - q) * (p[k] - q) <= 0) {
				++k;
			}
			l = k - 1 - j;
			r = n + j - k;
			ans += s[l] + s[r];
		}
		cout << 1LL * n * (n - 1) * (n - 2) / 6 - ans / 2 << endl;
NEXT:
		continue;
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//251430 	Jan 14, 2011 1:46:03 PM 	watashi 	E - Very simple problem 	GNU C++ 	Accepted 	800 ms 	25944 KB 

