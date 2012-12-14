#include <cstdio>
#include <numeric>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
int a[MAXN], b[MAXN], c[MAXN];

int main() {
	int na, nb, nc;

	while (scanf("%d%d", &na, &nb) != EOF && na > 0) {
		for (int i = 0; i < na; ++i) {
			scanf("%d", &a[i]);
		}
		sort(a, a + na);
		for (int i = 0; i < nb; ++i) {
			scanf("%d", &b[i]);
		}
		sort(b, b + nb);
		nc = set_union(a, a + na, b, b + nb, c) - c;
		printf("%d\n", accumulate(c, c + nc, 0));
	}

	return 0;
}
//715027  	2011-01-04 07:35:20 	Accepted	0.002	Minimum	26909	C++	4636 - Cubist Artwork
/*
id => 1174285
pid => 4636
pname => Cubist Artwork
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:49:34
*/
