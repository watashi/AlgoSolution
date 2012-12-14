#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1 << 20;

int p[MAXN];

int main() {
	int re, n;

	for (long long i = 2; i < MAXN; ++i) {
		if (p[i] > 0) {
			continue;
		}
		for (long long j = i, t = 1; j < MAXN; j *= i, ++t) {
			for (long long k = j; k < MAXN; k += j) {
				p[k] = max(p[k], (int)t);
			}
		}
	}
	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		printf("%d\n", p[n]);
	}

	return 0;
}

//ID 	Date (UTC) 	Status 	CPU 	Memory 	Author 	Source 	Problem / Title
//716505  	2011-01-07 08:50:01 	Accepted	0.074	Minimum	26909	C++	5110 - Square-Free Numbers

/*
id => 1174199
pid => 5110
pname => Square-Free Numbers
status => Accepted
lang => C++
time => 0.062
date => 2012-12-14 17:37:20
*/
