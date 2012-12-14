#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int re, n;
	long long a, b;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		b = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &a);
			while (a & 1) {
				a >>= 1;
			}
			b ^= a;
		}
		puts(b == 0 ? "NO" : "YES");
	}

	return 0;
}

//# 		Problem 	Verdict 	Language 	Run Time 	Submission Date
//798547 	5059 	Playing With Stones 	Accepted 	C++ 	0.008 	2011-05-13 11:16:31

/*
const int MAXN = 100;
int a[MAXN], sg[MAXN];

int main() {
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; j + j <= i; ++j) {
			a[sg[i - j]] = i;
		}
		for (int j = 0; ; ++j) {
			if (a[j] != i) {
				sg[i] = j;
				break;
			}
		}
		printf("[%d] = %d ", i, sg[i]);
		int t;
		putchar('(');
		t = i;
		while (t) {
			printf("%d", t & 1);
			t >>= 1;
		}
		putchar(')');
		putchar('(');
		t = sg[i];
		while (t) {
			printf("%d", t & 1);
			t >>= 1;
		}
		puts(")");
	}
	return 0;
}
*/

/*
id => 1174309
pid => 5059
pname => Playing With Stones
status => Accepted
lang => C++
time => 0.009
date => 2012-12-14 17:52:28
*/
