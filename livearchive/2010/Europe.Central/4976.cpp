#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 200200;
const int INF = 1000000007;
static int a[MAXN];

int main() {
	int re, n, x, y, p, q, ans;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		a[0] = -INF;
		fill(a + 1, a + 1 + n, INF);
		x = INF;
		p = q = ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &y);
			if (y > x) {
				++p;
				q = max<int>(q + 1, lower_bound(a, a + n, y) - a);
			} else {
				p = 1;
				q = lower_bound(a, a + n, y) - a;
			}
			x = y;
			a[p] = min<int>(a[p], x);
			ans = max<int>(ans, q);
		}
		printf("%d\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//722951  	2011-01-20 14:55:05 	Accepted	2.508	1180	26909	C++	4976 - Defense Lines

/*
id => 1174399
pid => 4976
pname => Defense Lines
status => Accepted
lang => C++
time => 0.535
date => 2012-12-14 18:44:20
*/
