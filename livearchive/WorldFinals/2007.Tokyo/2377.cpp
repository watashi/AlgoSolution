#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32768;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const double INF = 1e100;

double fmod_(double x, double y) {
	x = fmod(x, y);
	while (x < 0) {
		x += y;
	}
	return x;
}

int main() {
	int ri = 0, n;
	double theta, x, y, xx, yy, a[MAXN], c, cc;

	while (scanf("%d%lf", &n, &theta) != EOF && n > 0) {
		x = y = 0;
		c = cc = 0;
		for (int i = 1; i <= n; ++i) {
			scanf("%lf%lf", &xx, &yy);
			a[i] = atan2(yy - y, xx - x);
			if (xx < x - EPS) {
				c = cc = INF;
			}
			x = xx;
			y = yy;
		}
		sort(a + 1, a + n + 1);
		a[0] = a[n] - 2 * PI;
		a[n + 1] = a[1] + 2 * PI;
		
	//	printf("%lf and %lf\n", c, cc);
		for (int i = 1; i <= n; ++i) {
			if (a[i + 1] >= a[i] + PI - EPS) {
				c = min(c, fmod_(a[i] - PI / 2, 2 * PI));
				cc = min(cc, fmod_(PI / 2 - a[i], 2 * PI));
			}
			if (a[i - 1] <= a[i] - PI + EPS) {
				c = min(c, fmod_(a[i] + PI / 2, 2 * PI));
				cc = min(cc, fmod_(-PI / 2 - a[i], 2 * PI));
			}
		}

	//	printf("%lf and %lf\n", c, cc);
		printf("Case %d: ", ++ri);
		if (c < EPS || cc < EPS) {
			puts("Acceptable as proposed");
		} else if (c > INF / 2 && cc > INF / 2) {
			puts("Unacceptable");
		} else if (c <= cc + EPS) {
			printf("Acceptable after clockwise rotation of %.2lf degrees\n", c / PI * 180);
		} else {
			printf("Acceptable after counterclockwise rotation of %.2lf degrees\n", cc / PI * 180);
		}
		puts("");
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//727329  	2011-01-29 09:19:34 	Accepted	0.002	Minimum	26909	C++	2377 - Grand Prix

/*
id => 1174090
pid => 2377
pname => Grand Prix
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:21:07
*/
