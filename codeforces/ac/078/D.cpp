#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const double EPS = 5e-7;
const double H = 0.5 * sqrt(3.0);

double sqr(double x) {
	return x * x;
}

int ifloor(double x) {
	return (int)(floor(x + EPS) + .5);
}

int main() {
	int n, m;
	double r, x, y;
	long long ans = 0;

	cin >> n;
	r = n;
	for (int i = 0; i <= n; ++i) {
		x = 1.5 * i + 1.0;
		if (x > r + EPS) {
			break;
		}
		y = sqrt(fabs(r * r - x * x));
		if (i % 2 == 0) {
			m = ifloor(y / H) / 2 + 1;
			x = 1.5 * i + 0.5;
			y = sqrt(r * r - x * x);
			m = min(m, (ifloor(y / H) + 1) / 2);
			ans += m + m - 1;
			if (i > 0) {
				ans += m + m - 1;
			}
		} else {
			m = (ifloor(y / H) + 1) / 2;
			x = 1.5 * i + 0.5;
			y = sqrt(r * r - x * x);
			m = min(m, ifloor(y / H) / 2);
			ans += m + m;
			if (i > 0) {
				ans += m + m;
			}
		}
	}
	cout << ans << endl;

	return 0;
}

