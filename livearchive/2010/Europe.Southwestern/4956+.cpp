// if A * B = C then A * (B * x) = C * x

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int MAXN = 1024;

void mul(int n, unsigned a[MAXN][MAXN], unsigned x[MAXN], unsigned ret[MAXN]) {
	static int y[MAXN];
	for (int i = 0; i < n; ++i) {
		y[i] = 0;
		for (int j = 0; j < n; ++j) {
			y[i] += a[i][j] * x[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		ret[i] = y[i];
	}
}

unsigned a[MAXN][MAXN], x[MAXN], y[MAXN], z[MAXN];

int main() {
	int n;

	for (int i = 0; i < MAXN; ++i) {
		x[i] = rand();
	}
	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%u", &a[i][j]);
			}
		}
		mul(n, a, x, y);
		mul(n, a, y, y);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%u", &a[i][j]);
			}
		}
		mul(n, a, x, z);
		puts(memcmp(y, z, n * sizeof(unsigned)) == 0 ? "YES" : "NO");
	}
}

// long long ver.
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714960  	2011-01-04 03:51:20 	Accepted	15.061	8608	26909	C++	4956 - Comparing answers

// unsigned ver.
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714962  	2011-01-04 03:53:16 	Accepted	11.480	4500	26909	C++	4956 - Comparing answers
/*
id => 1174212
pid => 4956
pname => Comparing answers
status => Accepted
lang => C++
time => 0.496
date => 2012-12-14 17:39:19
*/
