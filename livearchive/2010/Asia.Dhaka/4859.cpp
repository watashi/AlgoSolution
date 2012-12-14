#include <cmath>
#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;
double _h[MAXN + 1];

double h(long long i) {
	return i <= MAXN ? _h[i] : log(i) + 0.57721571489839007540;
}

int main() {
	int ri = 0;
	long long w, l, a, b;
	double ans;

	_h[0] = 0;
	for (int i = 1; i <= MAXN; ++i) {
		_h[i] = _h[i - 1] + 1.0 / i;
	}
	while (scanf("%lld%lld", &w, &l) != EOF && !(w == 0 && l == 0)) {
		printf("Case %d:\n", ++ri);
		if (l == 0 && w % 8 == 0) {
			printf("On Average Bob Reaches Round 8.00\n");
		} else if (l == 0 && w % 8 != 0) {
			printf("Situation Impossible.\n");
		} else {
			a = max(0LL, (w - 7 * l + 7) / 8);
			b = w / 8;
			if (a > b) {
				printf("Situation Impossible.\n");
			} else {
				if (b - a > 10000) {
					ans = h(b + l) - h(a + l - 1);
				} else {
					ans = 0;
					for (long long i = a; i <= b; ++i) {
						ans += 1.0 / (i + l);
					}
				}
				ans *= (w + l) / (b - a + 1.0);
				printf("On Average Bob Reaches Round %.2lf\n", ans);			
			}
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714975  	2011-01-04 04:13:13 	Accepted	0.049	Minimum	26909	C++	4859 - Knockout Tournaments

/*
id => 1174071
pid => 4859
pname => Knockout Tournaments
status => Accepted
lang => C++
time => 0.045
date => 2012-12-14 17:18:41
*/
