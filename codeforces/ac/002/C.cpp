#include <cmath>
#include <cstdio>

const double EPS = 1e-8;

int main() {
	double x[3], y[3], z[3], a[2], b[2], c[2], d[2], delta, x1, x2, y1, y2, theta;

	for (int i = 0; i < 3; ++i) {
		scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
	}
	for (int i = 0; i < 2; ++i) {
		a[i] = -2 * (x[i] - x[2]);
		b[i] = -2 * (y[i] - y[2]);
		c[i] = z[i] * z[i] - z[2] * z[2];
		d[i] = (x[2] * x[2] - x[i] * x[i]) + (y[2] * y[2] - y[i] * y[i]);
		fprintf(stderr, "%lf %lf %lf\n", a[i], b[i], c[i]);
	}
	delta = a[0] * b[1] - b[0] * a[1];
	x1 = (c[0] * b[1] - b[0] * c[1]) / delta;
	x2 = (d[0] * b[1] - b[0] * d[1]) / delta;
	y1 = (a[0] * c[1] - c[0] * a[1]) / delta;
	y2 = (a[0] * d[1] - d[0] * a[1]) / delta;
	fprintf(stderr, "%lf %lf\n", x1, x2);
	fprintf(stderr, "%lf %lf\n", y1, y2);

	a[0] = x1 * x1 + y1 * y1;
	b[0] = 2 * (x1 * (x2 - x[0]) + y1 * (y2 - y[0])) - z[0] * z[0];
	c[0] = (x2 - x[0]) * (x2 - x[0]) + (y2 - y[0]) * (y2 - y[0]);
	delta = b[0] * b[0] - 4 * a[0] * c[0];
	fprintf(stderr, "%lf %lf %lf (%lf)\n", a[0], b[0], c[0], delta);
	if (fabs(a[0]) < EPS) {
		if (fabs(b[0]) < EPS) {
			theta = fabs(c[0]) < EPS ? 1 : -1;
		} else {
			theta = -c[0] / b[0];
		}
	} else if (delta > -EPS) {
		theta = (-b[0] - sqrt(fabs(delta))) / (2 * a[0]);
		if (theta < 1 - EPS) {
			theta = (-b[0] + sqrt(fabs(delta))) / (2 * a[0]);
		}
	} else {
		theta = -1;
	}
	if (theta > 1 - EPS) {
		printf("%.10lf %.10lf\n", x1 * theta + x2, y1 * theta + y2);
	}

	return 0;
}

//# 	When 	Who 	Problem 	Lang 	Verdict 	Time 	Memory
//255688 	Jan 20, 2011 7:34:36 PM 	watashi 	2C - Commentator problem 	GNU C++ 	Accepted 	30 ms 	1300 KB 

