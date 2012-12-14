#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long Mat[10][10];

const long long MOD = 1000000007LL;

void mul(int n, const Mat a, const Mat b, Mat ret) {
	static Mat c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < n; ++k) {
				c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret[i][j] = c[i][j];
		}
	}
}

void pow(int n, Mat a, long long b, Mat ret) {
	static Mat c;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = i == j ? 1 : 0;
		}
	}
	while (b > 0) {
		if ((b & 1) != 0) {
			mul(n, a, c, c);
		}
		mul(n, a, a, a);
		b >>= 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ret[i][j] = c[i][j];
		}
	}
}

void dump(int n, const Mat a) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%lld, ", a[i][j]);
		}
		puts("");
	}
}

Mat a;

int main() {
	int re, n, r, k;
	long long s[100], ans;
	
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d%d%d", &n, &r, &k);
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < r; ++j) {
				a[i][j] = i == j + 1 ? 1 : 0;
			}
		}
		for (int i = 0; i < r; ++i) {
			scanf("%lld", &s[i]);
		}
		for (int j = 0; j < r; ++j) {
			scanf("%lld", &a[0][j]);
		}
		for (int i = r; i < 20; ++i) {
			s[i] = 0;
			for (int j = 0; j < r; ++j) {
				s[i] = (s[i] + s[i - j - 1] * a[0][j]) % MOD;
			}
		}
		for (int i = 0; i < r; ++i) {
			s[i] = s[i + k - 1];
		}

	//	dump(r, a);
		pow(r, a, k, a);
	//	dump(r, a);
		for (int i = 0; i <= r; ++i) {
			a[r][i] = a[i][r] = 0;
		}
		a[r][r - 1] = a[r][r] = 1;
		pow(r + 1, a, n, a);
	//	dump(r + 1, a);
		ans = 0;
		for (int i = 0; i < r; ++i) {
			ans = (ans + a[r][i] * s[r - 1 - i]) % MOD;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716580  	2011-01-07 10:38:35 	Accepted	0.045	Minimum	26909	C++	5112 - Sales Prediction

/*
id => 1174191
pid => 5112
pname => Sales Prediction
status => Accepted
lang => C++
time => 0.012
date => 2012-12-14 17:35:58
*/
