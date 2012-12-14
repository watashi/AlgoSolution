#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 65536;

inline long long myabs(long long x) {
	return x < 0 ? -x : x;
}

int main() {
	bool blank = false;
	int n, q, a, b;
	long long ans;
	static long long x[MAXN], y[MAXN], z[MAXN];

	while (scanf("%d%d", &n, &q) != EOF && n > 0) {
		if (blank) {
			puts("");
		} else {
			blank = true;
		}

		for (int i = 0; i < n; ++i) {
			scanf("%lld%lld", &x[i], &y[i]);
		}
		x[n] = x[0];
		y[n] = y[0];
		z[0] = 0;
		for (int i = 0; i < n; ++i) {
			z[i + 1] = z[i] + x[i] * y[i + 1] - y[i] * x[i + 1];
		}
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", &a, &b);
			ans = myabs(z[b] - z[a] + x[b] * y[a] - y[b] * x[a]);
			ans = min(ans, myabs(z[n]) - ans);
			printf("%lld.%c\n", ans / 2, ans % 2 == 0 ? '0' : '5');
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716486  	2011-01-07 08:37:08 	Presentation Error	0.164	1936	26909	C++	5108 - Playing Field

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722970  	2011-01-20 15:28:32 	Accepted	0.162	1936	26909	C++	5108 - Playing Field

/*
id => 1174196
pid => 5108
pname => Playing Field
status => Accepted
lang => C++
time => 0.088
date => 2012-12-14 17:36:36
*/
