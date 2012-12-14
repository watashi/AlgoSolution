// GOOD PROBLEM
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 100;

typedef long long Matrix[MAXN][MAXN];

void dump(int n, Matrix a) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%4lld", a[i][j]);
		}
		puts(";");
	}
}

void mul(int n, int m, Matrix a, Matrix b, Matrix ret) {
	static Matrix c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= m;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret[i][j] = c[i][j];
		}
	}
}

void pow(int n, int m, Matrix a, int b, Matrix ret) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret[i][j] = i == j ? 1 : 0;
		}
	}
	while (b > 0) {
		if (b & 1) {
			mul(n, m, a, ret, ret);
		}
		b >>= 1;
		mul(n, m, a, a, a);
	}
}

// [0, 3n]
inline int range(int n, int begin, int end) {
	if (begin < end) {
		return begin;
	} else if (begin > end) {
		return n + begin - 1;
	} else {
		return n + n + begin;
	}
}

Matrix a, c;
int f[MAXN], full[MAXN * 3], head[MAXN * 3];

int iterate(int r, int n, const int a[]) {
	for (int i = 0; i < n; ++i) {
		r = a[r];
	}
	return r;
}

int main() {
	int n, b, m;
	bool inf;
	long long ans;

	while (scanf("%d", &n) != EOF && n > 0) {
		for (int i = 0; i <= n; ++i) {
			scanf("%d", &f[i]);
		}
		scanf("%d%d", &b, &m);
		for (int i = 0; i <= n; ++i) {
			full[range(n, i, i)] = range(n, f[i], f[i]);
			head[range(n, i, i)] = range(n, f[i], f[i]);	//
			if (i == n) {
				continue;
			}
			head[range(n, i, i + 1)] = range(n, f[i], f[i + 1]);
			head[range(n, i + 1, i)] = range(n, f[i + 1], f[i]);
			if (abs(f[i + 1] - f[i]) > 1) {
				full[range(n, i, i + 1)] = full[range(n, i + 1, i)] = 3 * n + 1;
			} else {
				full[range(n, i, i + 1)] = range(n, f[i], f[i + 1]);
				full[range(n, i + 1, i)] = range(n, f[i + 1], f[i]);	//
			}
			for (int j = 0; j < n; ++j) {
				a[j][i] = 0;
			}
			for (int j = min(f[i], f[i + 1]); j < max(f[i], f[i + 1]); ++j) {
				a[j][i] = 1;
			}
		}
		full[3 * n + 1] = 3 * n + 1;

//		dump(n, a);
		pow(n, m, a, b, c);
//		dump(n, c);
		ans = 0;
		inf = false;
		for (int i = 0; i <= n; ++i) {
			if (iterate(range(n, i, i), b, full) == range(n, i, i)) {
//				printf("add %d\n", i);
				++ans;
			}
			if (iterate(range(n, i, i + 1), b, full) == range(n, i, i + 1)) {
				inf = true;
			}
			if (i == n) {
				continue;
			}
			if (iterate(range(n, i, i + 1), b, head) == range(n, i, i + 1)) {
//				printf("del %d -> %d\n", i, i + 1);
				--ans;
			}
			if (iterate(range(n, i + 1, i), b, head) == range(n, i + 1, i)) {
//				printf("del %d -> %d\n", i + 1, i);
				--ans;
			}
			ans += c[i][i];
//			printf("[%d] %lld\n", i, c[i][i]);
		}

		if (inf) {
			puts("Infinity");
		} else {
			printf("%lld\n", ans % m);
		}
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714956  	2011-01-04 03:36:25 	Accepted	1.787	640	26909	C++	4955 - Periodic points

/*
id => 1174210
pid => 4955
pname => Periodic points
status => Accepted
lang => C++
time => 0.169
date => 2012-12-14 17:39:01
*/
