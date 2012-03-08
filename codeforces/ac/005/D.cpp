#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	double a, v, l, d, w;
	double s1, s2, s3, u, ans = 0;

	scanf("%lf%lf%lf%lf%lf", &a, &v, &l, &d, &w);
	w = min(v, w);
	s1 = v * v / a / 2;
	s2 = w * w / a / 2;
	s3 = s1 - s2;
	if (d < s2) {
		w = sqrt(2 * a * d);	// !
		ans += w / a;
	} else if (d < s1 + s3) {
		u = sqrt(a * d + w * w / 2);
		ans += u / a;
		ans += (u - w) / a;
	} else {
		ans += v / a;
		ans += (v - w) / a;
		ans += (d - s1 - s3) / v;
	}
	d = l - d;
	s3 = (v * v - w * w) / a / 2;	// !!
	if (d < s3) {
		u = sqrt(2 * a * d + w * w);
		ans += (u - w) / a;
	} else {
		ans += (v - w) / a;
		ans += (d - s3) / v;
	}
	printf("%.10lf\n", ans);

	return 0;
}

//#  	When  	Who  	Problem  	Lang  	Verdict  	Time  	Memory
//256033 	Jan 21, 2011 11:06:09 AM 	watashi 	5D - Follow Traffic Rules 	GNU C++ 	Accepted 	30 ms 	1300 KB 
