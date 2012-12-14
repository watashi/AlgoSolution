#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 22;
const long long MOD = 9999991;

long long c[MAXN][MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		c[i][0] = c[i][i] = 1LL;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

long long gao(int n, int a[]) {
	if (n == 0) {
		return 1LL;
	} else {
		int m = stable_partition(a + 1, a + n, bind2nd(less<int>(), a[0])) - a;
		long long ret = c[n - 1][n - m];
		ret = ret * gao(m - 1, a + 1) % MOD;
		ret = ret * gao(n - m, a + m) % MOD;
		return ret;
	}
}

int main() {
	int re, n, a[MAXN];

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		if (n < 1 || n > 20) {
			throw 1;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
		}
		printf("%d\n", (int)gao(n, a));
		sort(a, a + n);
		for (int i = 0; i < n; ++i) {
			if (a[i] != i) {
				throw 1;
			}
		}
	}

	return 0;
}
//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714857  	2011-01-03 16:38:56 	Accepted	0.066	Minimum	26909	C++	4847 - Binary Search Tree
// *stable*_partition
/*
id => 1174200
pid => 4847
pname => Binary Search Tree
status => Accepted
lang => C++
time => 0.029
date => 2012-12-14 17:37:25
*/
