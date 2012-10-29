#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-6;
double a[1024];

int main() {
	bool f;
	int n, s, t;
	double l, r, x, y;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &a[i]);
	}

	l = 1;
	r = 6e6;
	for (int k = 0; k < 100; ++k) {
		x = (l + r) / 2;
		f = true;
		for (int i = 1; f && i <= n; ++i) {
			if (i * x < a[i]) {
				f = false;
			}
		}
		if (!f) {
			l = x;
		} else {
			r = x;
		}
	}
	x = (l + r) / 2;

	l = 1;
	r = 6e6;
	for (int k = 0; k < 100; ++k) {
		y = (l + r) / 2;
		f = true;
		for (int i = 1; f && i <= n; ++i) {
			if (i * y >= a[i] + 1) {
				f = false;
			}
		}
		if (f) {
			l = y;
		} else {
			r = y;
		}
	}
	y = (l + r) / 2;

	s = (int)(x * (n + 1) + EPS);
	t = (int)(y * (n + 1) - EPS);
	if (s < t) {
		puts("not unique");
	} else {
		puts("unique");
		printf("%d\n", s);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//218381 	Dec 12, 2010 3:46:32 PM 	watashi 	C - The Race 	GNU C++ 	Accepted 	30 ms 	1300 KB 
