#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	double a, b, c, d;

	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << -1 << endl;
			} else {
				cout << 0 << endl;
			}
		} else {
			cout << 1 << endl << fixed << setprecision(10) << -c / b << endl;
		}
	} else {
		if (a < 0) {
			a = -a;
			b = -b;
			c = -c;
		}
		d = b * b - 4 * a * c;
		if (d < -1e-8) {
			cout << 0 << endl;
		} else {
			d = sqrt(fabs(d));
			if (d < 1e-8) {
				cout << 1 << endl << fixed << setprecision(20) << -b / (2 * a) << endl;
			} else {
				cout << 2 << endl;
				cout << fixed << setprecision(20) << (-b - d) / (2 * a) << endl;
				cout << fixed << setprecision(20) << (-b + d) / (2 * a) << endl;
			}
		}
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//278892 	Feb 11, 2011 6:09:45 PM 	watashi 	20B - Equation 	GNU C++ 	Accepted 	30 ms 	1300 KB 
