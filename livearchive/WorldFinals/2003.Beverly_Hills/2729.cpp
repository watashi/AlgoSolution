#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1.);

int main() {
	int ri = 0;
	double a1, b1, t1, a2, b2, c2, t2, t;
	double l, r, m, s, a, b, d;

	while (scanf("%lf%lf%lf%lf%lf%lf", &a1, &b1, &t1, &a2, &b2, &t) && t1 > 0) {
		t2 = sqrt((a2 * a2 * a2) / (a1 * a1 * a1)) * t1;
		t = fmod(t, t2) / t2;
		s = t * PI * a2 * b2;
		l = 0;
		r = 2 * PI;
		c2 = sqrt(a2 * a2 - b2 * b2);
		for (int i = 0; i < 100; ++i) {
			m = (l + r) / 2;
			d = (a2 * b2 * m - b2 * c2 * sin(m)) / 2;
			if (d < s) {
				l = m;
			} else {
				r = m;
			}
		}
		// fprintf(stderr, "%lf %lf %lf %lf\n", t, l, r, d);
		m = (l + r) / 2;
		a = a2 * cos(m);
		b = b2 * sin(m);
		printf("Solar System %d: %.3lf %.3lf\n", ++ri, a, b);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723408  	2011-01-21 17:20:21 	Accepted	0.002	Minimum	26909	C++	2729 - The Solar System
/*
id => 1174153
pid => 2729
pname => The Solar System
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:30:53
*/
