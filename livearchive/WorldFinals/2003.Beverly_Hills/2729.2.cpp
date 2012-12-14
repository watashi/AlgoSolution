#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const double PI = acos(-1.0);

double area(double a, double b, double x) {
	double y = 0, c = sqrt(a * a - b * b);
	y += a * a * (PI / 2 - asin(x / a));
	y -= x * sqrt(a * a - x * x);
	y += (x - c) * sqrt(a * a - x * x); // triangle
	y *= b / a;
	return y;
}

int main() {
	int ri = 0;
	bool flip;
	double a1, b1, t1, a2, b2, t2, t, l, r, m, s;

	while (scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &t1, &a2, &b2, &t) != EOF && t1 != 0) {
		t2 = sqrt(pow(a2 / a1, 3) * pow(t1, 2));
		t = fmod(t, t2);
		if (t > t2 / 2) {
			t = t2 - t;
			flip = true;
		} else {
			flip = false;
		}
		s = PI * a2 * b2;
		s *= 2 * t / t2;

		l = -a2;
		r = a2;
		while (r - l > EPS) {
			m = (l + r) / 2;
		//	printf("[%lf] => %lf\n", m, area(a2, b2, m));
			if (area(a2, b2, m) > s) {
				l = m;
			} else {
				r = m;
			}
		}

		m = (l + r) / 2;
		a1 = m;
		b1 = b2 / a2 * sqrt(a2 * a2 - m * m);
		if (flip) {
			b1 = -b1;
		}
		printf("Solar System %d: %.3lf %.3lf\n", ++ri, a1, b1);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723409  	2011-01-21 17:20:48 	Accepted	0.002	Minimum	26909	C++	2729 - The Solar System
/*
id => 1174154
pid => 2729
pname => The Solar System
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:57
*/
