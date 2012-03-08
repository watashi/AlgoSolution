#include <cmath>
#include <cstdio>

int main() {
	int n, m;
	double x, y, xx, yy, ans;

	scanf("%d%d", &n, &m);
	ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &x, &y);
		if (i > 0) {
			xx -= x;
			yy -= y;
			ans += hypot(xx, yy);
		}
		xx = x;
		yy = y;
	}
	ans *= m;
	printf("%.10lf\n", ans / 50);

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//863262 	Nov 14, 2011 4:23:26 PM 	watashi 	127A - Wasted Time 	GNU C++0x 	Accepted 	30 ms 	1300 KB 
