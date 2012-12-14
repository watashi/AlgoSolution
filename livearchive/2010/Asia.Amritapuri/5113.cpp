#include <cstdio>

int main() {
	int re, n, a, d;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d", &n, &a, &d);
		printf("%d\n", n * (n - 1) / 2 * d + n * a);
	}

	return 0;
}

// ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
// 714850  	2011-01-03 16:25:29 	Accepted	0.002	Minimum	26909	C++	5113 - Cookie Piles
/*
id => 1174188
pid => 5113
pname => Cookie Piles
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:35:38
*/
