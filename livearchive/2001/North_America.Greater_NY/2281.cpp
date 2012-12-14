#include <cstdio>

int sqr(int x) {
	return x * x;
}

int r[20], g[20], b[20];

int main() {
	int x, y, k;

	for (int i = 0; i < 16; ++i) {
		scanf("%d%d%d", &r[i], &g[i], &b[i]);
	}
	while (scanf("%d%d%d", &r[16], &g[16], &b[16]) != EOF && r[16] >= 0) {
		k = -1;
		for (int i = 0; i < 16; ++i) {
			x = sqr(r[16] - r[i]) + sqr(g[16] - g[i]) + sqr(b[16] - b[i]);
			if (k == -1 || y > x) {
				k = i;
				y = x;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r[16], g[16], b[16], r[k], g[k], b[k]);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//805899 	2281 	Color Me Less 	Accepted 	C++ 	0.008 	2011-05-23 14:46:11
/*
id => 1174047
pid => 2281
pname => Color Me Less
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:15:14
*/
