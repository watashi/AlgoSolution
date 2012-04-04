#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	long long t1, t0, t2, x1, x2;
	long long a, b, c, d, u, v;

	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	t1 = t0 - t1;
	t2 = t2 - t0;

	u = v = 0;
	if (t1 == 0 && t2 == 0) {
		u = x1;
		v = x2;
	} else if (t1 == 0) {
		u = x1;
	} else if (t2 == 0) {
		v = x2;
	} else {
		a = t2;
		b = 1;
		u = 0;
		v = x2;
		for (int i = 1; i <= x1; ++i) {
			int j = (t1 * i + t2 - 1) / t2;
			if (j > x2) {
				break;
			}
			c = j * t2 - i * t1;
			d = i + j;
			if (a * d > c * b || (a * d == c * b && i + j > u + v)) {
				a = c;
				b = d;
				u = i;
				v = j;
			}
		}
	}
	cout << u << " " << v << endl;

	return 0;
}

