#include <cstdio>
#include <algorithm>

using namespace std;

double x[1 << 20], v[1 << 20];

int main() {
	int n;
	bool f;
	double l, r, m, t;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &x[i], &v[i]);
	}
	l = 0;
	r = 9e9;
	for (int k = 0; k < 64; ++k) {
		m = (l + r) / 2;
		t = -1e99;
		f = false;
		for (int i = 0; !f && i < n; ++i) {
			if (v[i] > 0) {
				t = max(t, x[i] + v[i] * m);
			} else if (t >= x[i] + v[i] * m) {
				f = true;
			}
		}
		if (f) {
			r = m;
		} else {
			l = m;
		}
	}
	if (r < 8e9) {
		printf("%.10lf\n", (l + r) / 2);
	} else {
		puts("-1");
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//309011 	Feb 27, 2011 10:08:44 PM 	watashi 	24E - Berland collider 	GNU C++ 	Accepted 	1440 ms 	17700 KB 
