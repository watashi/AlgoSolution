#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 32768;

int main() {
	int re, n, k, d;
	static int a[MAXN];

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		d = a[k - 1] - a[0];
		for (int i = k; i < n; ++i) {
			d = min(d, a[i] - a[i - k + 1]);
		}
		printf("%d\n", d);
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714851  	2011-01-03 16:26:30 	Accepted	0.172	528	26909	C++	5114 - Christmas Play

/*
id => 1174192
pid => 5114
pname => Christmas Play
status => Accepted
lang => C++
time => 0.088
date => 2012-12-14 17:36:08
*/
