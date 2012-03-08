#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int re;
	double a, b, c, s, t, ans;

	cin >> re;
	for (int ri = 1; ri <= re; ++ri) {
		cin >> a >> b;
		if (b == 0) {
			ans = 1;
		} else if (a == 0) {
			ans = 0.5;
		} else {
			t = s = 2 * a * b;
			if (a < 4 * b) {
				c = a / 4;
				s -= a * (b - c);
				b = c;
			}
			s -= 2 * b * b;
			ans = s / t;
		}
		cout << fixed << setprecision(10) << ans << endl;
	}

	return 0;
}

