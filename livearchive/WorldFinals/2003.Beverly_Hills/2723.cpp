#include <cstdio>
#include <cmath>

using namespace std;

long long tri[10];
long long len[10];
long long dis[3][3] = {
	{0, 5, 6},
	{1, 4, 7},
	{2, 3, 8}
};

inline long long toit(double x) {
	return (long long)(x + 0.5 - 1e-8);
}

inline double hyp(double x, double y) {
	return sqrt(x * x + y * y);
}

long long gao(int n, long long x, long long y) {
	// printf("%d %lld %lld\n", n, x, y);
	if (n == 1) {
		return dis[x][y];
	} else {
		--n;
		long long xx = x / tri[n];
		long long yy = y / tri[n];
		x %= tri[n];
		y %= tri[n];
		if (yy == 1) {
			x = tri[n] - 1 - x;
		}
		if (xx == 1) {
			y = tri[n] - 1 - y;
		}
		return dis[xx][yy] * len[n] + gao(n, x, y);
	}
}

int main() {
	tri[0] = len[0] = 1;
	for (int i = 1; i < 10; ++i) {
		tri[i] = tri[i - 1] * 3;
		len[i] = len[i - 1] * 9;
	}

	int n, ri = 0;
	double x1, y1, x2, y2;
	long long xx1, yy1, xx2, yy2;
	double ans;

	while (scanf("%d", &n) != EOF && n != 0) {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		x1 *= tri[n] - 1;
		y1 *= tri[n] - 1;
		x2 *= tri[n] - 1;
		y2 *= tri[n] - 1;
		xx1 = toit(x1);
		yy1 = toit(y1);
		xx2 = toit(x2);
		yy2 = toit(y2);
		// fprintf(stderr, "%lf %lf %lf %lf\n", x1, y1, x2, y2);
		// fprintf(stderr, "%lld %lld\n", gao(n, xx1, yy1), gao(n, xx2, yy2));
		ans = fabs(gao(n, xx1, yy1) - gao(n, xx2, yy2));
		ans += hyp(xx1 - x1, yy1 - y1);
		ans += hyp(xx2 - x2, yy2 - y2);
		ans /= tri[n] - 1;
		if (ri != 0) {
			puts("");
		}
		printf("Case %d.  Distance is %.4lf\n", ++ri, ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//723405  	2011-01-21 17:16:44 	Accepted	0.002	Minimum	26909	C++	2723 - Riding the Bus

/*
id => 1174155
pid => 2723
pname => Riding the Bus
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:31:02
*/
