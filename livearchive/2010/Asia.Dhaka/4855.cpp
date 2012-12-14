#include <cstdio>

using namespace std;

const int MAXN = 64;
long long fib[100];

int main() {
	int re, n;
	long long a, b, c;

	fib[0] = fib[1] = 1;
	for (int i = 2; i < MAXN; ++i) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		c = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a);
			b = 0;
			for (int j = MAXN - 1; a > 0; --j) {
				if (a >= fib[j]) {
					a -= fib[j];
					++b;
				}
			}
			c *= b;
		}
		printf("Case %d: %lld\n", ri, c);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//714973  	2011-01-04 04:09:45 	Accepted	0.002	Minimum	26909	C++	4855 - Hyper Box
/*
id => 1174073
pid => 4855
pname => Hyper Box
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:18:45
*/
