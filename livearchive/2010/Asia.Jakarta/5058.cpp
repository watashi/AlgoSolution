#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

const int MAXN = 1024;
const long long MOD = 1000003;
int a[MAXN];
long long c[MAXN][MAXN];

void init() {
	for (int i = 0; i < MAXN; ++i) {
		c[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

long long gao(int n, int a[]) {
	if (n == 0) {
		return 1LL;
	} else {
		int m = a[0];
		int l = stable_partition(a, a + n, bind2nd(less<int>(), m)) - a;
		int r = (a + n) - stable_partition(a + l, a + n, bind2nd(equal_to<int>(), m));
//		printf("@%d: %d %d\n", m, l, r);
		return gao(l, a) * gao(r, a + l + 1) % MOD * c[n - 1][l] % MOD;
	}
}

int main() {
	int re, n, m;

	init();
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		printf("%lld\n", c[m][n] * gao(n, a) % MOD);
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798549 	5058 	Counting BST 	Accepted 	C++ 	0.036 	2011-05-13 11:17:11
/*
id => 1174308
pid => 5058
pname => Counting BST
status => Accepted
lang => C++
time => 0.038
date => 2012-12-14 17:52:20
*/
